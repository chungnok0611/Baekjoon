a = input()
print(a[2],end='')
print(a[1],end='')
print(a[0])

#for문 활용
word = input()

for item in word[::-1]:
    print(item, end='')