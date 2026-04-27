a = sorted(list(map(int, input().split())))
print(sum(a) if sum(a[:2]) > a[2] else 2*sum(a[:2]) - 1)