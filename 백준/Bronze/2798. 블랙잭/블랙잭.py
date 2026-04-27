import sys

N, M = map(int, sys.stdin.readline().split())
card = list(map(int, sys.stdin.readline().split()))

arr = []
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            s = card[i]+card[j]+card[k]
            if s <= M:
                arr.append(s)
print(max(arr))
