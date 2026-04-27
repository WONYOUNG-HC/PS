import sys
from collections import deque

node = int(sys.stdin.readline())
edge = int(sys.stdin.readline())
graph = [[0] * (node + 1) for _ in range(node+1)]
for _ in range(edge):
    a, b = map(int, sys.stdin.readline().split())
    graph[a][b] = 1
    graph[b][a] = 1


def bfs(s, visited):
    queue = deque()
    queue.append(s)
    visited[s] = True
    while queue:
        v = queue.popleft()
        for i in range(1, node+1):
            if graph[v][i] == 1 and not visited[i]:
                visited[i] = True
                queue.append(i)


def main():
    visited = [False] * (node+1)
    bfs(1, visited)
    cnt = 0
    for i in range(2, node+1):
        if visited[i]:
            cnt += 1
    print(cnt)


if __name__ == '__main__':
    main()
