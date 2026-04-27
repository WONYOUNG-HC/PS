import sys
from collections import deque

n, q = int(input()), deque()
while True:
    a = int(sys.stdin.readline())
    if a == -1:
        break
    elif a == 0:
        q.popleft()
    elif len(q) < n:
        q.append(a)
print('empty') if len(q) == 0 else print(*q)