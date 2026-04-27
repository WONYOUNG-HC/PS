import sys

N, M = map(int, input().split())
dic = {}
for i in range(N):
    name = sys.stdin.readline().rstrip()
    dic[name] = 0
cnt = 0
res = []
for i in range(M):
    name = sys.stdin.readline().rstrip()
    if name in dic:
        res.append(name)
        cnt += 1
print(cnt)
res.sort()
for i in range(cnt):
    print(res[i])
