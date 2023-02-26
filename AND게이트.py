#퍼셉트론(단순,인공뉴런)
def AND(x1,x2):               #AND함수
  w1,w2,theata = 0.5,0.5,0.7  #가중치2개, 임계값
  tmp = x1*w1 + x2*w2
  if tmp <= theata:
    print(0)
    return 0
  elif tmp > theata:
    return 1
AND(0,0) #0출력
AND(1,0) #0출력
AND(0,1) #0출력
AND(1,1) #1출력