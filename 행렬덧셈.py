A, B = [], []

a, b = map(int, input().split())

for row in range(a):
    row = list(map(int, input().split()))
    A.append(row)

for row in range(a):
    row = list(map(int, input().split()))
    B.append(row)
    
for row in range(a):
    for col in range(b):
        print(A[row][col] + B[row][col], end=' ')
    print()

        

