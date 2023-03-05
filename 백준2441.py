a=int(input())
for i in range(0,a):
  print(end=' '*(i))
  for j in range(0,a-i):
    print(end='*')
    if(j==a-i-1):
      print('')