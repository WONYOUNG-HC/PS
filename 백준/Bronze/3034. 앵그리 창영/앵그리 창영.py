n, w, h = map(int, input().split())
for i in range(n):
    print('DA' if w**2 + h**2 >= int(input())**2 else 'NE')