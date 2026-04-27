N, M = map(int, input().split())

newBoard = []
for i in range(N):
    s = input()
    newBoard.append(list(s))

line1 = ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']
line2 = ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']
white = []
black = []
for i in range(4):
    white.append(line1)
    black.append(line2)
    white.append(line2)
    black.append(line1)

w_num = []
b_num = []
for i in range(N-7):
    for j in range(M-7):
        w_cnt = 0
        b_cnt = 0
        for u in range(i, i+8):
            for v in range(j, j+8):
                if white[u-i][v-j] != newBoard[u][v]:
                    w_cnt += 1
                if black[u-i][v-j] != newBoard[u][v]:
                    b_cnt += 1
        w_num.append(w_cnt)
        b_num.append(b_cnt)

w = min(w_num)
b = min(b_num)

if w > b:
    print(b)
else:
    print(w)
