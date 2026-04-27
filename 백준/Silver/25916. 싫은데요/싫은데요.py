import sys

n, m = map(int, input().split())
arr = list(map(int, sys.stdin.readline().split()))

left, right = 0, 0
cur = 0
ans = 0

while right < n:
    if cur + arr[right] <= m:
        cur += arr[right]
        right += 1

        ans = max(ans, cur)
    else:
        cur -= arr[left]
        left += 1

        if left > right:
            right = left
            cur = 0

print(ans)