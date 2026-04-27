for _ in range(int(input())):
    i = ['0', '']
    for j in range(int(input())):
        a = list(input().split())
        if int(a[0]) > int(i[0]):
            i = a
    print(i[1])