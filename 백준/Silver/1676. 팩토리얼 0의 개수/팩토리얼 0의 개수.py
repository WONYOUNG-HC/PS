n = int(input())
fac = 1
for i in range(1, n+1):
    fac *= i
fac = list(str(fac))
p = len(fac) - 1
while fac[p] != '0' and p != 0:
    p -= 1
cnt = 0
if fac[p] == '0':
    while fac[p] == '0' and p != 0:
        p -= 1
        cnt += 1
print(cnt)
