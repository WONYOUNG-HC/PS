for _ in range(int(input())):
    a, b, c = map(int, input().split())
    print('does not matter' if b - c == a else 'advertise' if a < b - c else 'do not advertise')