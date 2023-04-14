a=int(input())
for i in range(1,a+1):
  print(end=' '*(a-i))
  for j in range(0,i*2-1):
    print(end='*')
    if(j==i*2-2):
      print('')
for i in range(0,a):
  for k in range(0,i+1):
    print(' ',end="")
  for j in range(0,a-i-1):
    print('*',end="")
  for l in range(0,a-i-2):
    print('*',end="")
    if(l==a-i-3):
      print("")