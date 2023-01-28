a=int(input())
for i in range(1,a+1):
   for j in range(a-i,a):
        print(end='*')
        if(j==a-1):
            print('')