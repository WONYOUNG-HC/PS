x, y, w, h = map(int, input().split())
arr = [h-y, y, x, w-x]
print(min(arr))