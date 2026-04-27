n = int(input())

num = 666
cnt = 0
flag = True

while flag:
    t = str(num)

    continuity = False
    for i in range(len(t)):
        if t[i] == '6':
            if i + 2 < len(t):
                continuity = True
                for j in range(1, 3):
                    if t[i+j] != '6':
                        continuity = False
        if continuity is True:
            cnt += 1
            break

    if cnt == n:
        flag = False
    num += 1

print(num-1)
