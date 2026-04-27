import sys


def divide(left, right, person):
    if person == 1:
        sort = sorted(arr[left:right+1])
        arr[left:right+1] = sort
        return

    mid = (left + right) // 2
    person //= 2
    divide(left, mid, person)
    divide(mid+1, right, person)


n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
k = int(sys.stdin.readline())

divide(0, n-1, k)
for i in range(n):
    print(arr[i], end=' ')
