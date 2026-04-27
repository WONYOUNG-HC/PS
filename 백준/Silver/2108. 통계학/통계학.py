import sys
from collections import Counter

N = int(sys.stdin.readline())
nums = [0 for _ in range(N)]
for i in range(N):
    nums[i] = int(sys.stdin.readline())
nums.sort()

average = sum(nums)/N
if average > 0:
    neg = False
else:
    average = -average
    neg = True
average_int = int(average)
if average > average_int + 0.5:
    average = average_int + 1
else:
    average = average_int
if neg:
    average = -average
print(average)

print(nums[N//2])

c = Counter(nums)
order = c.most_common()
maximum = order[0][1]
k = 1
max_list = [order[0][0]]
while k < len(order) and order[k][1] == maximum:
    max_list.append(order[k][0])
    k += 1
max_list.sort()
if len(max_list) == 1:
    print(max_list[0])
else:
    print(max_list[1])

print(nums[N-1] - nums[0])
