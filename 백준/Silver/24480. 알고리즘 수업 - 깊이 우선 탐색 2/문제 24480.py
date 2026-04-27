import sys
sys.setrecursionlimit(10**7)

def dfs(x):
    global cnt
    vis[x] = True
    ans[x] = cnt
    cnt += 1
    for y in sorted(adj[x], reverse=True):
        if not vis[y]:
            dfs(y)

n, m, r = map(int, input().split())
adj, vis, ans = [[] for _ in range(n + 1)], [False for _ in range(n + 1)], [0 for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    adj[u].append(v)
    adj[v].append(u)

cnt = 1
dfs(r)
for x in ans[1:]:
    print(x)