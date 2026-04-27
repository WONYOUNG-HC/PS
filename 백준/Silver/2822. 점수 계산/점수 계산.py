arr = [(int(input()), i) for i in range(8)]
arr.sort(key=lambda x: x[0], reverse=True)
a, b = 0, []
for x in arr[:5]:
    a += x[0]
    b.append(x[1] + 1)
b.sort()
print(a, *b)