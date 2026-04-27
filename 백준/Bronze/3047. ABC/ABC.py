arr = sorted(list(map(int, input().split())))
s = input()
for c in s:
    print(arr[ord(c) - ord('A')], end=' ')