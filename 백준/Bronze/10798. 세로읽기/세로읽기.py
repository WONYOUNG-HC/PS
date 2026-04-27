s = []
for _ in range(5):
    s.append(input())
for i in range(max(len(s[k]) for k in range(5))):
    for j in range(5):
        if (len(s[j]) > i):
            print(s[j][i], end='')