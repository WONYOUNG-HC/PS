import sys

n = int(input())
tmp = list(map(int, sys.stdin.readline().split()))
arr = []
for i in range(n):
    arr.append([tmp[i], i, 0])
arr.sort()
for i in range(1, n):
    if arr[i][0] == arr[i-1][0]:
        arr[i][2] = arr[i-1][2]
    else:
        arr[i][2] = arr[i-1][2] + 1
arr.sort(key=lambda x: x[1])
for i in range(n):
    print(arr[i][2], end=" ")
