x, y = [0]*3, [0]*3
for i in range(3):
    x[i], y[i] = input().split()
x.sort(); y.sort()
print(x[0] if x[1] == x[2] else x[2], y[0] if y[1] == y[2] else y[2])