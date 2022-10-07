a,d,n=map(int, input().split())
i = a
c=0
arith=[]
while c < n:
    arith.append(i)
    i +=d
    c += 1
print(arith[-1])