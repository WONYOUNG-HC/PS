N = int(input())
result = 0

for i in range(N+1):
    arr = list(map(int, str(i)))
    s = i + sum(arr)
    if s == N:
        result = i
        break
print(result)
