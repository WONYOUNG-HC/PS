n, m, l = map(int, input().split())
arr = [0 for _ in range(n)]

cnt = 0
cur = 0
arr[0] = 1

while arr[cur] < m:
    if arr[cur] % 2 == 1:
        cur = (cur + l) % n
    else:
        cur = (cur - l + n) % n
        
    arr[cur] += 1
    cnt += 1
    
print(cnt)