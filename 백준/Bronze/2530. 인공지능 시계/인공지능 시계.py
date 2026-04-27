a, b, c = map(int, input().split())
d = (a * 60**2 + b * 60 + c + int(input())) % (60**2 * 24)
print(d // 60**2, d % 60**2 // 60, d % 60)