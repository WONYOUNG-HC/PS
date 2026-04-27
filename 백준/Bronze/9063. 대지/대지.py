x1, y1, x2, y2 = 100000, 100000, -10000, -10000
for _ in range(int(input())):
    x, y = map(int, input().split())
    x1, y1 = min(x1, x), min(y1, y)
    x2, y2 = max(x2, x), max(y2, y)
print((x2-x1)*(y2-y1))