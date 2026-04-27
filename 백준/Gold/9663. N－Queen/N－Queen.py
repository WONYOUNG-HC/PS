n = int(input())
board = [0] * n
cnt = 0


def promising(queen, x):
    y = queen
    for i in range(queen):
        q_y, q_x = i, board[i]

        if x == q_x:
            return False
        elif y - q_y == x - q_x:
            return False
        elif y + x == q_y + q_x:
            return False
    return True


def backtracking(queen):
    if queen == n:
        global cnt
        cnt += 1
        return

    for x in range(n):
        if promising(queen, x):
            board[queen] = x
            backtracking(queen+1)


backtracking(0)
print(cnt)
