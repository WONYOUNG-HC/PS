import sys

n, m = map(int, sys.stdin.readline().split())
x, y = [], []
for  _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    x.append(a)
    y.append(b)

x.sort()
y.sort()

p, q = x[m // 2], y[m // 2]
ans = 0
for i in range(m):
    ans += abs(x[i] - p) + abs(y[i] - q)
print(ans)