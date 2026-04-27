import sys
st = []
for _ in range(int(input())):
    a = list(map(int, sys.stdin.readline().split()))
    if a[0] == 1:
        st.append(a[1])
    elif a[0] == 2:
        print(-1 if len(st) == 0 else st[-1])
        if len(st):
            st.pop()
    elif a[0] == 3:
        print(len(st))
    elif a[0] == 4:
        print(1 if len(st) == 0 else 0)
    else:
        print(-1 if len(st) == 0 else st[-1])
