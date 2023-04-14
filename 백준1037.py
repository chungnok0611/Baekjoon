a = int(input())
b = []
b = list(map(int, input().split()))
c = sorted(b)
print(c[-1]*c[0])