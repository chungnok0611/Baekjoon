import os
import openai

openai.api_key = "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"
while True:
    
  prompt = input("지시사항 입력 : ")
  if(prompt=="break"):
    print("꺼져")
    break
  response = openai.Completion.create(
  model="text-davinci-003",
  prompt=prompt,
  temperature=1,
  max_tokens=4000 ,
  #top_p=1.0,
  #frequency_penalty=0.0,
  #presence_penalty=0.0
)

  print("===========================================")
  print(response["choices"][0]["text"].strip())
  print("===========================================")