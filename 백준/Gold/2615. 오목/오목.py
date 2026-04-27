import sys

direction = [[[-1, 0], [1, 0]],  # 북 남
             [[0, -1], [0, 1]],  # 서 동
             [[-1, -1], [1, 1]],  # 북서 남동
             [[-1, 1], [1, -1]]]  # 북동 남서
board = []
for i in range(19):
    board.append(list(map(int, sys.stdin.readline().split())))


def check(a, b):
    if 0 <= a < 19 and 0 <= b < 19:
        return True
    return False


for y in range(19):
    for x in range(19):
        for color in (1, 2):
            if board[y][x] == color:
                for k in range(4):
                    start = [(x, y)]
                    p_ny, p_nx = y + direction[k][0][0], x + direction[k][0][1]
                    # 위로 방향
                    cnt = 1
                    while check(p_ny, p_nx) and board[p_ny][p_nx] == color:
                        start.append((p_nx, p_ny))
                        cnt += 1
                        if cnt > 5:
                            break
                        p_ny, p_nx = p_ny + direction[k][0][0], p_nx + direction[k][0][1]
                    n_ny, n_nx = y + direction[k][1][0], x + direction[k][1][1]
                    # 밑으로 방향
                    while check(n_ny, n_nx) and board[n_ny][n_nx] == color:
                        start.append((n_nx, n_ny))
                        cnt += 1
                        if cnt > 5:
                            break
                        n_ny, n_nx = n_ny + direction[k][1][0], n_nx + direction[k][1][1]
                    if cnt == 5:
                        print(color)
                        start.sort()
                        print(start[0][1]+1, start[0][0]+1)
                        sys.exit(0)
print(0)
