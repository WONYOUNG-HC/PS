L = int(input())
st = input()
st = list(st)
num = 0
for i in range(L):
    num += (ord(st[i])-96) * (31**i)
print(num % 1234567891)
