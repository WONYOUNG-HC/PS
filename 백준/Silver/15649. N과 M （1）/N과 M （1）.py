def backtracking():
    if (len(ans) == m):
        print(*ans)
        return
    
    for i in range(1, n+1):
        if i not in ans:
            ans.append(i)
            backtracking()
            ans.pop()

n, m = map(int, input().split())
arr = list(range(1, n+1))

ans = []
backtracking()