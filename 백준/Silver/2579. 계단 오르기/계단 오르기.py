n = int(input())
stair = [0 for _ in range(n+1)]
for i in range(1, n+1):
    stair[i] = int(input())
dp = [[0, 0] for _ in range(n+1)]
dp[1][0], dp[1][1] = stair[1], stair[1]
for i in range(2, n+1):
    dp[i][0] = max(dp[i-2][0] + stair[i], dp[i-2][1] + stair[i])
    dp[i][1] = dp[i-1][0] + stair[i]
print(max(dp[n]))
