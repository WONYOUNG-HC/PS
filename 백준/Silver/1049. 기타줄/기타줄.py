import sys

n, m = map(int, sys.stdin.readline().split())
set, single = 1000, 1000
for _ in range(m):
	a, b = map(int, sys.stdin.readline().split())
	set = a if a < set else set
	single = b if b < single else single

print(min(set*(n//6 + 1), set*(n//6) + single*(n%6), single*n))
