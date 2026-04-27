a, b = map(int, input().split())
mul = a * b
if b > a:
    a, b = b, a
while b != 0:
    r = a % b
    a, b = b, r
gcd = a
lcm = mul // gcd
print(gcd)
print(lcm)
