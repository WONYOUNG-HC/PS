input(); s = input()
a, b = s.count('A'), s.count('B')
print('Tie' if a == b else 'A' if a > b else 'B')