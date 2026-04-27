n, arr = int(input()), []
for _ in range(n):
    arr.append(float(input()))
for i in range(1, n):
    arr[i] = max(arr[i], arr[i] * arr[i - 1])
print('%0.3f' % max(arr))