a, b = int(input()), int(input())
c = (a - 1) * 31 + b
print('Special' if c == 49 else 'Before' if c < 49 else 'After')