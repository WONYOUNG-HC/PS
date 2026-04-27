from math import hypot, ceil

x, y, c = map(int, input().split())
dist = hypot(x, y)

if dist == 0:
    print(0)
elif dist == c:
    print(1)
else:
    print(max(2, ceil(dist / c)))
