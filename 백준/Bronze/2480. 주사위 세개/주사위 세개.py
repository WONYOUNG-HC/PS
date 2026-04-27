a = sorted(list(map(int, input().split()))); ans = 0
if a[0] == a[1] and a[1] == a[2]:
    ans = 10000 + a[0]*1000
elif a[0] == a[1]:
    ans = 1000 + a[0]*100
elif a[1] == a[2]:
    ans = 1000 + a[1]*100
else:
    ans = a[2]*100
print(ans)