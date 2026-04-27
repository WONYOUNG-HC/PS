def divide(n):
    if n == 1:
        return ['*']

    ret = divide(n//3)
    star = []

    for i in ret:
        star.append(i*3)
    for i in ret:
        star.append(i + ' '*(n//3) + i)
    for i in ret:
        star.append(i*3)

    return star


n = int(input())
result = divide(n)
print('\n'.join(result))
