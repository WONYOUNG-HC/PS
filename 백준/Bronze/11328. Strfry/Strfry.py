s = sorted
for _888 in range(int(input())):
  a, b = input().split()
  print('Possible' if s(a) == s(b) else 'Impossible')