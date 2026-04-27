a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = [a[0]*b[1] + b[0]*a[1], a[1]*b[1]]
t = [c[0], c[1]]
while t[1] != 0:
    t = [t[1], t[0] % t[1]]
print(c[0]//t[0], c[1]//t[0])