import sys
from collections import deque

n, m, r = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)

vis = [0 for _ in range(n + 1)]
q = deque([r])
vis[r] = 1
cnt = 2

while q:
    x = q.popleft()
    for y in sorted(adj[x], reverse=True):
        if vis[y] == 0:
            q.append(y)
            vis[y] = cnt
            cnt += 1

for x in vis[1:]:
    print(x)