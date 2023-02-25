a=int(input())
for i in range(1,a+1):
  print(end=' '*(a-i))
  for j in range(0,i):
    print(end='*')
    if(j==i-1):
      print('')