n = int(input())
arr = []
for i in range(n):
    arr.append(input())

h = 0
for a in arr:
    sp = a.split('X')
    for x in sp:
        if len(x) > 1:
            h += 1

tp = ["" for _ in range(n)]
for i in range(n):
    for j in range(n):
        tp[i] += arr[j][i]

w = 0
for a in tp:
    sp = a.split('X')
    for x in sp:
        if len(x) > 1:
            w += 1

print(h, w)