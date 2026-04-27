a = [input() for _ in range(3)]
print(int(a[0]) + int(a[2]) if a[1] == '+' else int(a[0]) * int(a[2]))