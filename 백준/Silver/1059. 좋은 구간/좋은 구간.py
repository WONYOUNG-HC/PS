l = int(input())
s = set(map(int, input().split()))
n = int(input())

ans = 0
for a in range(1, 1000):
    if a in s:
        continue
    for b in range(a + 1, 1001):
        if b in s:
            break
        if a <= n <= b:
            ans += 1
print(ans)