a, n = [0, 1, 2] + [0 for _ in range(1000000)], int(input())
for i in range(3, n + 1):
    a[i] = (a[i - 1] + a[i - 2]) % 15746
print(a[n])