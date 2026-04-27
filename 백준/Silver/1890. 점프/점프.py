n = int(input())
arr, dp = [], []
for _ in range(n):
    arr.append(list(map(int, input().split())))
    dp.append([0 for _ in range(n)])

dp[0][0] = 1
for i in range(n):
    for j in range(n):
        if arr[i][j] == 0:
            continue
        if i + arr[i][j] < n:
            dp[i + arr[i][j]][j] += dp[i][j]
        if j + arr[i][j] < n:
            dp[i][j + arr[i][j]] += dp[i][j]

print(dp[n - 1][n - 1])