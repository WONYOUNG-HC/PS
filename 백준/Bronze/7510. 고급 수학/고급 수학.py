for i in range(int(input())):
    a = sorted(list(map(int, input().split())))
    print(f'Scenario #{i+1}:')
    print('yes\n' if a[2]**2 == a[0]**2 + a[1]**2 else 'no\n')