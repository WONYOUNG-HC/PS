while True:
    a, b, c = input().split()
    if a == '#':
        break
    if int(b) > 17 or int(c) >= 80:
        a += ' Senior'
    else:
        a += ' Junior'
    print(a)