s = input()
while s != '0':
    palin = True
    left, right = 0, len(s)-1
    for i in range(len(s)//2):
        if s[left] == s[right]:
            pass
        else:
            palin = False
            break
        left += 1
        right -= 1
    if palin:
        print('yes')
    else:
        print('no')
    s = input()
