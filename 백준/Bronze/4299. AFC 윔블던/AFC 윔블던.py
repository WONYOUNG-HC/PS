a, b = map(int, input().split())
x = (a + b) // 2
if x - b < 0 or x < 0 or (a + b) % 2 != 0:
    print(-1)
else:
    print(*sorted([x, x - b], reverse=True))