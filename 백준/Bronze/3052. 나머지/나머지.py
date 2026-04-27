v, c = [False]*42, 0
for _ in range(10):
	i = int(input())
	if v[i%42] is False:
		v[i%42] = True
		c += 1
print(c)