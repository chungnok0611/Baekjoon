a=list(243,231,23,12,23,24)
n=0
j = -1
for i in a:
    for j in a:
        if a[j]>a[i]:
            a[j]=n
            a[j]=a[i]
            a[i]=n

for k in a:
    print(k)