from collections import Counter

for tc in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    cnt = Counter(arr)
    res = {}

    ex = 0
    for i in range(n):
        if cnt[arr[i]] < 6:
            ex += 1
            continue

        if arr[i] in res:
            res[arr[i]].append(i + 1 - ex)
        else:
            res[arr[i]] = [i + 1 - ex]

    ans = (0, 1e9)
    for i in res:
        if len(res[i]) != 6:
            continue
        
        if sum(res[i][:4]) < ans[1] or (sum(res[i][:4]) == ans[1] and res[i][4] < res[ans[0]][4]):
            ans = (i, sum(res[i][:4]))
    
    print(ans[0])