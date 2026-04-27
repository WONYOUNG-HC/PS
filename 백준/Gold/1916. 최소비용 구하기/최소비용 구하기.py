import sys
import heapq
INF = sys.maxsize

node = int(sys.stdin.readline())
edge = int(sys.stdin.readline())
graph = [[] for _ in range(node+1)]
for _ in range(edge):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))
dp = [INF] * (node+1)


def dijkstra():
    dp[start] = 0
    queue = []
    heapq.heappush(queue, (0, start))

    while queue:
        dist, cur = heapq.heappop(queue)
        if dp[cur] < dist:
            continue
        for i in range(len(graph[cur])):
            cost = dp[cur] + graph[cur][i][1]
            if dp[graph[cur][i][0]] > cost:
                dp[graph[cur][i][0]] = cost
                heapq.heappush(queue, (cost, graph[cur][i][0]))


start, end = map(int, sys.stdin.readline().split())
dijkstra()
print(dp[end])
