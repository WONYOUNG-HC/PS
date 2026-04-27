import sys

direction = [[[-1, 0], [1, 0]],  # 북 남
             [[0, -1], [0, 1]],  # 서 동
             [[-1, -1], [1, 1]],  # 북서 남동
             [[-1, 1], [1, -1]]]  # 북동 남서


def check(a, b):
    if 0 <= a < 19 and 0 <= b < 19:
        return True
    return False


board = [[0]*19 for _ in range(19)]
n = int(sys.stdin.readline())
for i in range(n):
    if i % 2:
        color = 1
    else:
        color = 2
    y, x = map(int, sys.stdin.readline().split())
    y, x = y-1, x-1
    board[y][x] = color

    for k in range(4):
        p_ny, p_nx = y + direction[k][0][0], x + direction[k][0][1]
        # 위로 방향
        cnt = 1
        while check(p_ny, p_nx) and board[p_ny][p_nx] == color:
            cnt += 1
            if cnt > 5:
                break
            p_ny, p_nx = p_ny + direction[k][0][0], p_nx + direction[k][0][1]
        n_ny, n_nx = y + direction[k][1][0], x + direction[k][1][1]
        # 밑으로 방향
        while check(n_ny, n_nx) and board[n_ny][n_nx] == color:
            cnt += 1
            if cnt > 5:
                break
            n_ny, n_nx = n_ny + direction[k][1][0], n_nx + direction[k][1][1]
        if cnt == 5:
            print(i+1)
            sys.exit(0)
print(-1)
