ans = 0;
for i in input():
    if i == 'S': i = 'R'
    j = (ord(i) - 65) // 3
    if j <= 5:
        ans += j + 3
    elif 'T' <= i <= 'V':
        ans += 9
    else:
        ans += 10
print(ans)
    