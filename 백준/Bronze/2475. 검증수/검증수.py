a = list(map(int, input().split()))
s = 0
for x in a: s += x**2
print(s % 10)