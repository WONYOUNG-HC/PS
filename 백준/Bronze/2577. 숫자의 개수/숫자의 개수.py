from functools import reduce
a = [int(input()) for _ in range(3)]
t = [0]*10
for i in list(str(reduce(lambda x,y:x*y, a))):
	t[int(i)]+=1
for i in t:
	print(i)