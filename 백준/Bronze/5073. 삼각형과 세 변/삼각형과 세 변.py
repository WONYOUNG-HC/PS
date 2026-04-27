while True:
    a = sorted(list(map(int, input().split())))
    if sum(a) == 0:
        break
    if a[0] + a[1] <= a[2]:
        print('Invalid')
    else:
        print(['', 'Equilateral', 'Isosceles', 'Scalene'][len(set(a))])
    