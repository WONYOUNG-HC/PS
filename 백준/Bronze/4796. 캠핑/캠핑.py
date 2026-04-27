for i in range(1, int(1e9)):
	l, p, v = map(int, input().split())
	if l == 0:
		break
	print(f'Case {i}: {(v // p * l) + (min(v % p, l))}')