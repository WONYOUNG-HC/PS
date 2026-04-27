import sys

for _ in range(3):
	sum = 0
	for i in range(int(sys.stdin.readline())):
		sum += int(sys.stdin.readline())
	if sum > 0:
		print('+')
	elif sum < 0:
		print('-')
	else:
		print(0)