m = int(input())
n = int(input())
prime = [True for _ in range(n + 1)]
prime[1] = False

for i in range(2, n + 1):
    if not prime[i]:
        continue
    
    j = i * 2
    while j <= n:
        prime[j] = False
        j += i
    
ans = []
for i in range(m, n + 1):
    if prime[i]:
        ans.append(i)

if ans:
    print(sum(ans))
    print(ans[0])
else:
    print(-1)