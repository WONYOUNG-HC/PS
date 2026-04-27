import sys

INF = sys.maxsize
node, edge = map(int, sys.stdin.readline().split())
graph = [[INF]*node for _ in range(node)]
for i in range(node):
    graph[i][i] = 0
for _ in range(edge):
    a, b = map(int, sys.stdin.readline().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

for k in range(node):
    for i in range(node):
        for j in range(node):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

score = [[0, 0] for _ in range(node)]
for i in range(node):
    score[i][1] = i+1
for i in range(node):
    for j in range(node):
        score[i][0] += graph[i][j]
score.sort()
print(score[0][1])
