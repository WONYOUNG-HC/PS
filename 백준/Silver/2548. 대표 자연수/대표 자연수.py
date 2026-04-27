n = int(input())
arr = sorted(list(map(int, input().split())))
a, b = 0, 0
for x in arr:
    a += abs(x - arr[n // 2 - 1])
    b += abs(x - arr[n // 2])
print(arr[n // 2 - 1] if a <= b else arr[n // 2])