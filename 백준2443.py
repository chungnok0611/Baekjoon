a = int(input())
for i in range(0,a):
  for k in range(0,i):
    print(' ',end="")
  for j in range(0,a-i):
    print('*',end="")
  for l in range(0,a-i-1):
    print('*',end="")
    if(l==a-i-2):
      print("")