import sys

document = list(sys.stdin.readline().rstrip())
word = list(sys.stdin.readline().rstrip())

wlen = len(word)
i, cnt = 0, 0
while (i < len(document)):
	if (document[i:i+wlen] == word):
		cnt += 1
		i += wlen
	else:
		i += 1
		
print(cnt)
