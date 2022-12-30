a=int(input()) 
list1=list(map(int,input())) #공백없이 입력받고 리스트(배열)의 저장
sum=0
for i in range(0,a):
    sum+=list1[i]
print(sum)