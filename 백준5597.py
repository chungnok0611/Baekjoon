a=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
for i in range(0,28):
    b=int(input())
    for j in range(1,31):
        if(b-j==0):
            a[b-1]=0
for i in range(0,30):
    if(a[i]!=0):
        print(a[i])