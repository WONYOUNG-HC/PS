import sys
# '.'-'A' = -19

n = int(sys.stdin.readline())
tree = [[-19]*3 for _ in range(n)]
tree[0][0] = -1
for i in range(n):
    tmp = sys.stdin.readline().rstrip()
    c, l, r = ord(tmp[0]) - 65, ord(tmp[2]) - 65, ord(tmp[4]) - 65
    tree[c][1] = l
    tree[c][2] = r
    if l > 0:
        tree[l][0] = c
    if r > 0:
        tree[r][0] = c


def pre_order(cur):
    print(chr(cur+65), end='')
    if tree[cur][1] != -19:
        pre_order(tree[cur][1])
    if tree[cur][2] != -19:
        pre_order(tree[cur][2])


def in_order(cur):
    if tree[cur][1] != -19:
        in_order(tree[cur][1])
    print(chr(cur+65), end='')
    if tree[cur][2] != -19:
        in_order(tree[cur][2])


def post_order(cur):
    if tree[cur][1] != -19:
        post_order(tree[cur][1])
    if tree[cur][2] != -19:
        post_order(tree[cur][2])
    print(chr(cur+65), end='')


pre_order(0)
print()
in_order(0)
print()
post_order(0)
