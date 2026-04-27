import sys

n, k = map(int, sys.stdin.readline().split())
dp = [0] + list(map(int, sys.stdin.readline().split()))
for i in range(1, n+1):
	dp[i] += dp[i-1]

ans = -1000000000
for i in range(k, n+1):
	ans = max(ans, dp[i] - dp[i-k])

print(ans)
