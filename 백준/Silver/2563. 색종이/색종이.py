arr = [[0 for _ in range(110)] for _ in range(110)]
for _ in range(int(input())):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            arr[i][j] = 1
    
ans = 0
for i in range(1, 101):
    ans += sum(arr[i])
print(ans)