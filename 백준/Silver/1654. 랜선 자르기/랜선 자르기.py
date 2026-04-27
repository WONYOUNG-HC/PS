import sys

K, N = map(int, input().split())
arr = [int(sys.stdin.readline()) for _ in range(K)]

up, down = max(arr), 1
answer = []
while up >= down:
    cnt = 0
    mid = (up + down) // 2
    for i in arr:
        cnt += i // mid
    if cnt >= N:
        answer.append(mid)
        down = mid + 1
    else:
        up = mid - 1
print(max(answer))
