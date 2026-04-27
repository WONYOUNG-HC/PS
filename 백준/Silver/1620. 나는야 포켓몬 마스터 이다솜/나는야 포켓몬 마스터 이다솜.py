import sys

N, M = map(int, input().split())
dic_name_key = {}
dic_num_key = {}
for i in range(1, N+1):
    name = sys.stdin.readline().rstrip()
    dic_num_key[i] = name
    dic_name_key[name] = i
for j in range(M):
    k = sys.stdin.readline().rstrip()
    if k.isdigit():
        print(dic_num_key[int(k)])
    else:
        print(dic_name_key[k])
