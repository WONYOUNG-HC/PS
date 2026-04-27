x = int(input())

left, right = 0, x
while left <= right:
    mid = (left + right) // 2
    if mid**2 <= x < (mid+1)**2:
        print(mid)
        break
    elif x > mid**2:
        left = mid+1
    else:
        right = mid-1