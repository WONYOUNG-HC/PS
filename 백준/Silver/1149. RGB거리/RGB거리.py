import sys

n = int(input())

dp = [[0 for _ in range(3)] for _ in range(n)]
for i in range(n):
    dp[i][0], dp[i][1], dp[i][2] = map(int, sys.stdin.readline().split())
    if i < 1:
        continue
    for j in range(3):
        if j == 0:
            dp[i][j] += min(dp[i-1][1], dp[i-1][2])
        elif j == 1:
            dp[i][j] += min(dp[i-1][0], dp[i-1][2])
        else:
            dp[i][j] += min(dp[i-1][0], dp[i-1][1])

print(min(dp[n-1][0], dp[n-1][1], dp[n-1][2]))
