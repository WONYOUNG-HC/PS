import sys

def cut(row, col, N):
    global neg, zer, pos
    n = board[row][col]

    for i in range(row, row + N):
        for j in range(col, col+N):
            if board[i][j] != n:
                N //= 3
                cut(row, col, N)
                cut(row, col + N, N)
                cut(row, col + (2 * N), N)
                cut(row + N, col, N)
                cut(row + N, col + N, N)
                cut(row + N, col + (2 * N), N)
                cut(row + (2 * N), col, N)
                cut(row + (2 * N), col + N, N)
                cut(row + (2 * N), col + (2 * N), N)
                return

    if n == -1:
        neg += 1
    elif n == 1:
        pos += 1
    elif n == 0:
        zer += 1


N = int(input())
board = [list(map(int, sys.stdin.readline().split())) for i in range(N)]
neg, zer, pos = 0, 0, 0

cut(0, 0, N)
print(neg)
print(zer)
print(pos)
