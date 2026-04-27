ans = 0
for _ in range(int(input())):
    ans += [1, 5, 10, 50][(int(input().split()[0]) - 136) // 6] * 1000
print(ans)