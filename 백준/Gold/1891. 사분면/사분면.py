def find_pos(n1, n2, m1, m2, idx):
    if idx == len(num):
        return n1, m1
    if num[idx] == '1':
        return find_pos(n1, (n1+n2)//2, (m1+m2)//2, m2, idx+1)
    elif num[idx] == '2':
        return find_pos(n1, (n1+n2)//2, m1, (m1+m2)//2, idx+1)
    elif num[idx] == '3':
        return find_pos((n1+n2)//2, n2, m1, (m1+m2)//2, idx+1)
    elif num[idx] == '4':
        return find_pos((n1+n2)//2, n2, (m1+m2)//2, m2, idx+1)


def find_num(n1, n2, m1, m2):
    global answer
    if len(answer) == d:
        return answer

    if n1 <= nx < (n1+n2)//2 and (m1+m2)//2 <= ny < m2:
        answer += '1'
        return find_num(n1, (n1+n2)//2, (m1+m2)//2, m2)
    elif n1 <= nx < (n1+n2)//2 and m1 <= ny < (m1+m2)//2:
        answer += '2'
        return find_num(n1, (n1+n2)//2, m1, (m1+m2)//2)
    elif (n1+n2)//2 <= nx < n2 and m1 <= ny < (m1+m2)//2:
        answer += '3'
        return find_num((n1+n2)//2, n2, m1, (m1+m2)//2)
    elif (n1+n2)//2 <= nx < n2 and (m1+m2)//2 <= ny < m2:
        answer += '4'
        return find_num((n1+n2)//2, n2, (m1+m2)//2, m2)


d, num = map(int, input().split())
num = str(num)
x, y = map(int, input().split())
n, m = 2**d, 2**d

dx, dy = find_pos(0, n, 0, m, 0)
nx, ny = -1*y + dx, x + dy
answer = ''

if 0 <= nx < n and 0 <= ny < m:
    print(int(find_num(0, n, 0, m)))
else:
    print(-1)
