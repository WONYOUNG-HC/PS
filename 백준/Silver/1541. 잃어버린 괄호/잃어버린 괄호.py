import sys

exp = list(sys.stdin.readline().rstrip())
exp.append('-')
stack = []
tmp = []
answer = []
idx = 0
sidx = 0
aidx = 0
while idx != len(exp):
    while exp[idx].isdigit():
        tmp.append(int(exp[idx]))
        idx += 1

    l = len(tmp)
    stack.append(0)
    for i in range(l):
        stack[sidx] += tmp[i] * 10**(l-1-i)
    sidx += 1
    tmp.clear()

    if exp[idx] == '-':
        answer.append(0)
        for i in range(sidx):
            answer[aidx] += stack[i]
        aidx += 1
        stack.clear()
        sidx = 0
    idx += 1
result = answer[0]
for i in range(1, aidx):
    result -= answer[i]
print(result)
