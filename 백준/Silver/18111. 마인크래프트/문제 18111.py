import sys

n, m, b = map(int, sys.stdin.readline().split())
total = n * m
board = []
for _ in range(n):
    tmp = list(map(int, sys.stdin.readline().split()))
    board += tmp
board.sort()

time = 0
while board[0] != board[-1]:
    left, right = 0, total - 1
    minimum, maximum = board[0], board[-1]
    cut, put = 0, 0

    while board[left] == minimum:
        left += 1
        put += 1
        if put > b:
            put = -1
            break

    while board[right] == maximum:
        right -= 1
        cut += 2

    if put != -1 and cut >= put:
        time += put
        for i in range(left):
            board[i] += 1
            b -= 1
    else:
        time += cut
        for i in range(right+1, total):
            board[i] -= 1
            b += 1

print(time, board[0])
