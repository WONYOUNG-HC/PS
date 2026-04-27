import sys
from collections import deque

# 문제해석 : 언제 토마토가 다 익는 최소 일. 익은 토마토는 다음날 인접한 안익은 토마토를 익게함. 입력은 가로->세로->그래프
# 수학적 언어로 표현 : 그래프에서 상하좌우로 인접한 그래프 탐색.
# 설계 : bfs 사용. 그래프 탐색을 위한 for문 2개.
# 복잡도 계산 : 1000 * 1000 = 1000000
# 구현 설계
# 구현

direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]

m, n = map(int, sys.stdin.readline().split())
tomato = []
graph = []
for i in range(n):
    width = list(map(int, sys.stdin.readline().split()))
    for j in range(m):
        if width[j] == 1:
            tomato.append((i, j))
    graph.append(width)

queue = deque()
day = 0
while tomato:
    for t in tomato:
        queue.append(t)
    tomato.clear()

    while queue:
        y, x = queue.popleft()
        for k in range(4):
            dy, dx = direction[k]
            ny, nx = y + dy, x + dx

            if 0 <= ny < n and 0 <= nx < m:
                if graph[ny][nx] == 0:
                    graph[ny][nx] = 1
                    tomato.append((ny, nx))

    day += 1

for y in range(n):
    for x in range(m):
        if graph[y][x] == 0:
            print(-1)
            sys.exit(0)
print(day-1)
