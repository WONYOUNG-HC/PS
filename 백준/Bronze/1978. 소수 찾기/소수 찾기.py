import sys

N = int(input())
nums = list(map(int, sys.stdin.readline().split()))

cnt = 0
for i in range(N):
    prime = True
    if nums[i] == 1 or nums[i] % 2 == 0:
        prime = False
    if nums[i] == 2:
        prime = True
    else:
        for j in range(3, nums[i] // 2):
            if nums[i] % j == 0:
                prime = False
                break
    if prime:
        cnt += 1
print(cnt)
