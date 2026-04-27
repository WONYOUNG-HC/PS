import sys

N = int(input())

arr = []
for i in range(N):
    s = sys.stdin.readline().rstrip()
    tmp = [len(s), s]
    arr.append(tmp)
arr.sort(key=lambda x: x[0])

left = 0
right = 1
answer = []
while left < N:
    if left == N-1:
        answer.append(arr[left][1])
        left += 1
    elif arr[left][0] == arr[right][0]:
        tmp = [arr[left][1], arr[right][1]]
        right += 1
        while right <= N-1 and arr[left][0] == arr[right][0]:
            tmp.append(arr[right][1])
            right += 1
        tmp.sort()
        for i in range(right - left):
            answer.append(tmp[i])
        left = right
        right += 1
    else:
        answer.append(arr[left][1])
        left += 1
        right += 1

for i in range(N):
    if i > 0 and answer[i-1] == answer[i]:
        continue
    else:
        print(answer[i])
