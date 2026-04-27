a = [int(input()) for _ in range(3)]; ans = ''
if a[0] == 60 and a[1] == 60 and a[2] == 60:
    ans = 'Equilateral'
elif sum(a) == 180 and (a[0] == a[1] or a[1] == a[2] or a[0] == a[2]):
    ans = 'Isosceles'
elif sum(a) == 180:
    ans = 'Scalene'
else:
    ans = 'Error'
print(ans)