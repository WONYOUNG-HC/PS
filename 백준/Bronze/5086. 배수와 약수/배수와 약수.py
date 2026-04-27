while True:
    a, b = map(int, input().split())
    if a + b == 0:
        break
    if a < b and b % a == 0:
        print('factor')
    elif a % b == 0:
        print('multiple')
    else:
        print('neither')