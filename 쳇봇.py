import nltk
nltk.download('punkt')
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()

import numpy 
import tflearn
import tensorflow as tf
import random

from flask import Flask, request, jsonify
from flask_ngrok import run_with_ngrok

import json
with open('intents.json') as file:
    data = json.load(file)

words = []
labels = []
docs_x = []
docs_y = []

for intent in data['intents']:
    for pattern in intent['patterns']:
        wrds = nltk.word_tokenize(pattern)
        words.extend(wrds)
        docs_x.append(wrds)
        docs_y.append(intent["tag"])

    if intent['tag'] not in labels:
        labels.append(intent['tag'])

words = [stemmer.stem(w.lower()) for w in words if w != "?"]
words = sorted(list(set(words)))

labels = sorted(labels)

training = []
output = []

out_empty = [0 for _ in range(len(labels))]

for x, doc in enumerate(docs_x):
    bag = []

    wrds = [stemmer.stem(w.lower()) for w in doc]

    for w in words:
        if w in wrds:
            bag.append(1)
        else:
            bag.append(0)

    output_row = out_empty[:]
    output_row[labels.index(docs_y[x])] = 1

    training.append(bag)
    output.append(output_row)

training = numpy.array(training)
output = numpy.array(output)

tf.compat.v1.reset_default_graph()

net = tflearn.input_data(shape=[None, len(training[0])])
net = tflearn.fully_connected(net, 8)
net = tflearn.fully_connected(net, 8)
net = tflearn.fully_connected(net, len(output[0]),activation="softmax")
net = tflearn.regression(net, optimizer='adam', learning_rate=0.01, loss='categorical_crossentropy')

model = tflearn.DNN(net)

model.fit(training,output,n_epoch=1500, batch_size=8, show_metric=True)
model.save("model.tflearn")

def bag_of_words(s, words):
    bag = [0 for _ in range(len(words))]
    s_words = nltk.word_tokenize(s)
    s_words = [stemmer.stem(word.lower()) for word in s_words]

    for se in s_words:
        for i, w in enumerate(words):
            if w == se:
                bag[i] = 1

    return numpy.array(bag)

app = Flask(__name__)
run_with_ngrok(app)

@app.route('/', methods=['POST'])
def post():
  if request.method == 'POST':
    inp = request.get_json()["message"]
    if inp is not None:
      results = model.predict([bag_of_words(inp,words)])
      results_index = numpy.argmax(results)
      tag = labels[results_index]

      for tg in data["intents"]:
          if tg["tag"] == tag:
              responses = tg['responses']
      
      response = jsonify({
          'message': random.choice(responses)
      })
      response.status_code = 200
      return response

app.run()


# def chat():
#     print("start talking with your bot (type quit to stop)!")
#     while True:
#         inp = input("You: ")
#         if inp.lower() == "quit":
#             break

#         results = model.predict([bag_of_words(inp,words)])
#         results_index = numpy.argmax(results)
#         tag = labels[results_index]

#         for tg in data["intents"]:
#             if tg["tag"] == tag:
#                 responses = tg['responses']

#         print(  random.choice(responses))
# chat()
