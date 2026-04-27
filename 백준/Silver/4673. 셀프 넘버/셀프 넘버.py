vis = [False] * 10010
for i in range(10001):
    i = i + sum(map(int, str(i)))
    while i <= 10000 and  not vis[i]:
        vis[i] = True
        i = i + sum(map(int, str(i)))
for i in range(10001):
    if not vis[i]:
        print(i)