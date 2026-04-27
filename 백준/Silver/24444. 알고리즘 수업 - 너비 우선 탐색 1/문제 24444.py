import sys
from collections import deque

n, m, r = map(int, input().split())
adj, vis = [[] for _ in range(n + 10)], [False for _ in range(n + 10)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)

q = deque([r])
vis[r] = True
cur, ans = 1, [0 for _ in range(n + 10)]
while q:
    x = q.popleft()
    ans[x] = cur
    cur += 1
    for y in sorted(adj[x]):
        if not vis[y]:
            vis[y] = True
            q.append(y)
        
for i in range(1, n + 1):
    print(ans[i])