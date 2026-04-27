import sys
sys.setrecursionlimit(5000)

dx = [1, -1, 0, 0, 1, -1, -1, 1]
dy = [0, 0, 1, -1, -1, 1, -1, 1]


def dfs(y, x):
    visited[y][x] = True
    for d in range(8):
        nx, ny = x + dx[d], y+dy[d]
        if nx < 0 or nx >= w or ny < 0 or ny >= h:
            continue
        if graph[ny][nx] and not visited[ny][nx]:
            dfs(ny, nx)


while True:
    w, h = map(int, sys.stdin.readline().split())
    if w == 0 and h == 0:
        break
    graph = []
    visited = [[False]*w for _ in range(h)]
    for i in range(h):
        graph.append(list(map(int, sys.stdin.readline().split())))

    cnt = 0
    for i in range(h):
        for j in range(w):
            if graph[i][j] and not visited[i][j]:
                dfs(i, j)
                cnt += 1
    print(cnt)
