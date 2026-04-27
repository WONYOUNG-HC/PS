import sys
input = sys.stdin.readline

n, d = map(int, input().split())
graph = [[] for _ in range(d + 1)]
for _ in range(n):
    start, end, dist = map(int, input().split())
    if end > d:
        continue
    graph[start].append((end, dist))
    
dist = [i for i in range(d+1)]
for cur in range(d+1):
    if cur > 0:
        dist[cur] = min(dist[cur], dist[cur-1] + 1)
    for next in graph[cur]:
        dist[next[0]] = min(dist[next[0]], dist[cur] + next[1])

print(dist[d])