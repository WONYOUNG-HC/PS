n = input(); t = n; cnt = 0
while True:
    cnt += 1
    if len(t) == 1:
        t = '0' + t[0]
    t = t[1] + str(sum(map(int, t)) % 10)
    if int(t) == int(n):
        break
print(cnt)
    