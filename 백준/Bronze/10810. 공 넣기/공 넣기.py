n, m = map(int, input().split())
a = [0 for _ in range(n + 1)]
for _ in range(m):
    i, j, k = map(int, input().split())
    while i <= j:
        a[i] = k
        i += 1
for i in a[1:]:
    print(i, end=' ')