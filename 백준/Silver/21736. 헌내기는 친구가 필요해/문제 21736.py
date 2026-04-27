from collections import deque

graph = [['X' for _ in range(610)]]
vis = [[False for _ in range(610)] for _ in range(610)]
dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]

n, m = map(int, input().split())
for i in range(1, n + 1):
    graph.append('X' + input() + 'X')
    for j in range(1, m + 1):
        if graph[i][j] == 'I':
            pos = [i, j]
graph.append(['X' for _ in range(610)])

ans = 0
q = deque([pos])
vis[pos[0]][pos[1]] = True
while q:
    p = q.popleft()
    for d in dir:
        np = [p[0] + d[0], p[1] + d[1]]
        if vis[np[0]][np[1]]:
            continue
        if graph[np[0]][np[1]] == 'X':
            continue
        if graph[np[0]][np[1]] == 'P':
            ans += 1
        vis[np[0]][np[1]] = True
        q.append(np)
        
print(ans if ans else 'TT')