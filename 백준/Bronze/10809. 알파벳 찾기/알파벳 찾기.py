d = {}
for i, c in enumerate(input()):
    if c not in d: d[c] = i
for i in range(97, 123):
    print(d[chr(i)] if chr(i) in d else -1, end=' ')