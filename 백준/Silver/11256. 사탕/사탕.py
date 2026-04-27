for tc in range(int(input())):
    j, n = map(int, input().split())
    arr = []
    for _ in range(n):
        a, b = map(int, input().split())
        arr.append(a * b)
    arr.sort(reverse=True)
    ans = 1
    for a in arr:
        j -= a
        if j <= 0:
            break
        ans += 1
    print(ans)