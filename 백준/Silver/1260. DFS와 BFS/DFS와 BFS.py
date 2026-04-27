import sys
from collections import deque

node, edge, start = map(int, sys.stdin.readline().split())
graph = [[0] * (node + 1) for _ in range(node+1)]
for _ in range(edge):
    a, b = map(int, sys.stdin.readline().split())
    graph[a][b] = 1
    graph[b][a] = 1


def dfs(s, visited):
    visited[s] = True
    print(s, end=' ')

    for i in range(1, node+1):
        if graph[s][i] == 1 and not visited[i]:
            dfs(i, visited)


def bfs(s, visited):
    queue = deque()
    queue.append(s)
    visited[s] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in range(1, node+1):
            if graph[v][i] == 1 and not visited[i]:
                visited[i] = True
                queue.append(i)


def main():
    visited = [False] * (node+1)
    dfs(start, visited)
    print()
    visited = [False] * (node+1)
    bfs(start, visited)


if __name__ == '__main__':
    main()
