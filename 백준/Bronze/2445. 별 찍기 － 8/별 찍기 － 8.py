n = int(input()) + 1
for i in range(1, n):
    print('*' * i, end='')
    print(' ' * (n - i - 1) * 2, end='')
    print('*' * i)
for i in range(n - 2, 0, -1):
    print('*' * i, end='')
    print(' ' * (n - i - 1) * 2, end='')
    print('*' * i)