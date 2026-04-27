c, n, m = map(int, input().split())
ans = (c*n)-m 
if ans > 0:
    print(ans)
else:
    print(0)
