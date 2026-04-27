import sys

INF = sys.maxsize
node = int(sys.stdin.readline())
edge = int(sys.stdin.readline())
graph = [[INF]*(node+1) for _ in range(node+1)]
for i in range(1, node+1):
    graph[i][i] = 0
for _ in range(edge):
    a, b, c = map(int, sys.stdin.readline().split())
    if graph[a][b] < c:
        continue
    graph[a][b] = c

for k in range(1, node+1):
    for i in range(1, node+1):
        for j in range(1, node+1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

for i in range(1, node+1):
    for j in range(1, node+1):
        print(0 if graph[i][j] == INF else graph[i][j], end=' ')
    print()
