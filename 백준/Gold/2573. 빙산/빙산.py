import sys
from collections import deque

direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]

m, n = map(int, sys.stdin.readline().split())
graph = []
for _ in range(m):
    width = list(map(int, sys.stdin.readline().split()))
    graph.append(width)


def iceberg():
    ice = []
    visited = [[False] * n for _ in range(m)]

    for u in range(m):
        for v in range(n):
            if graph[u][v] > 0:
                queue = deque()
                queue.append((u, v))
                visited[u][v] = True

                while queue:
                    y, x = queue.popleft()
                    adjacency = 0
                    for k in range(4):
                        dy, dx = direction[k]
                        ny, nx = y + dy, x + dx
                        if 0 <= ny < m and 0 <= nx < n:
                            if graph[ny][nx] <= 0:
                                adjacency += 1
                            elif graph[ny][nx] > 0 and visited[ny][nx] is False:
                                queue.append((ny, nx))
                                visited[ny][nx] = True
                    ice.append((y, x, adjacency))

                for y, x, adjacency in ice:
                    graph[y][x] -= adjacency

                for y in range(u, m):
                    for x in range(n):
                        if graph[y][x] > 0 and visited[y][x] is False:
                            return 1
                return 2
    return 3


def main():
    year = 0

    while True:
        cond = iceberg()
        if cond == 1:
            print(year)
            return
        elif cond == 2:
            year += 1
        elif cond == 3:
            print(0)
            return


if __name__ == '__main__':
    main()
