n = int(input())

flag = True
cnt = 1

if n == 1:
    flag = False

point = 2
difference = 5
while flag:
    if point <= n <= point + difference:
        flag = False

    point += difference + 1
    difference += 6
    cnt += 1

print(cnt)
