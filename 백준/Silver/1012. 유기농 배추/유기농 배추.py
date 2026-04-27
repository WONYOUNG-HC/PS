import sys
sys.setrecursionlimit(5000)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def dfs(y, x):
    visited[y][x] = True
    for d in range(4):
        nx, ny = x + dx[d], y+dy[d]
        if nx < 0 or nx >= m or ny < 0 or ny >= n:
            continue
        if graph[ny][nx] and not visited[ny][nx]:
            dfs(ny, nx)


for tc in range(int(sys.stdin.readline())):
    m, n, k = map(int, sys.stdin.readline().split())
    graph = [[0]*m for _ in range(n)]
    visited = [[False]*m for _ in range(n)]
    for _ in range(k):
        a, b = map(int, sys.stdin.readline().split())
        graph[b][a] = 1

    cnt = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] and not visited[i][j]:
                dfs(i, j)
                cnt += 1

    print(cnt)
