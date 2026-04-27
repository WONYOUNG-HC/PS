from collections import deque

start, end = map(int, input().split())
INF = 100000
visited = [0] * (INF + 1)


def bfs(s):
    queue = deque([s])
    while queue:
        v = queue.popleft()
        if v == end:
            print(visited[v])
            return
        for i in (v-1, v+1, v*2):
            if 0 <= i <= INF and not visited[i]:
                visited[i] = visited[v] + 1
                queue.append(i)


bfs(start)
