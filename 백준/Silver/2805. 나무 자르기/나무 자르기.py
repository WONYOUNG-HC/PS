import sys

N, M = map(int, sys.stdin.readline().split())
tree = list(map(int, sys.stdin.readline().split()))

down, up = 0, max(tree)
res = []
while up >= down:
    mid = (up + down) // 2
    cut = 0
    for i in tree:
        if i - mid > 0:
            cut += i - mid
    if cut >= M:
        res.append(mid)
        down = mid + 1
    else:
        up = mid - 1
print(max(res))
