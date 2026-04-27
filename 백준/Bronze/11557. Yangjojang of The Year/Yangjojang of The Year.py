for _ in range(int(input())):
  arr = []
  for i in range(int(input())):
    arr.append(list(input().split()))
  arr.sort(key=lambda x: int(x[1]), reverse=True)
  print(arr[0][0])