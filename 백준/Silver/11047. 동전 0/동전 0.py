n, k = map(int, input().split())
coin = [0 for _ in range(n)]
for i in range(n):
    coin[i] = int(input())
cnt = 0
n -= 1
while k:
    cnt += k // coin[n]
    k %= coin[n]
    n -= 1
print(cnt)
