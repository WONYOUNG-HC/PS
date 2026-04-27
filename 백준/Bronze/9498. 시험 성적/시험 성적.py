a = int(input())
a = 3 if a == 100 else a//10-6
print('F' if a < 0 else ('D', 'C', 'B', 'A')[a])