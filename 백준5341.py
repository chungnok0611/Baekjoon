a=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
b=0
for i in a:
    a[b]=int(input())
    if(a[b]==0):
        break
    b=b+1
for i in range(0,b+1):
    if(i!=0):
        print(sum)   
    sum=0
    for k in range(0,a[i]):
        sum+=a[i]-k