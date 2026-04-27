a, b = 0, 0
for i in range(1, 10):
    t = int(input())
    if t > a: a, b = t, i
print(a, b)