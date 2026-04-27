import sys
N = int(input())
spec = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
for i in range(N):
    grade = 1
    weight = spec[i][0]
    height = spec[i][1]
    for j in range(N):
        if weight < spec[j][0] and height < spec[j][1]:
            grade += 1
    spec[i].append(grade)
for i in range(N):
    print(spec[i][2], end=" ")
