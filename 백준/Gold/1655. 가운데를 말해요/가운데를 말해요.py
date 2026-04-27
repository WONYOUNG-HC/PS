import sys
import heapq

n = int(sys.stdin.readline())
if n < 2:
    print(int(sys.stdin.readline()))
else:
    max_heap = [-int(sys.stdin.readline())]
    min_heap = [int(sys.stdin.readline())]
    ans = str(-max_heap[0]) + '\n'
    if -max_heap[0] > min_heap[0]:
        max_heap[0], min_heap[0] = -min_heap[0], -max_heap[0]
    ans += str(-max_heap[0]) + '\n'
for i in range(2, n):
    num = int(sys.stdin.readline())
    if i % 2:
        if num < min_heap[0]:
            heapq.heappush(max_heap, -num)
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
        else:
            heapq.heappush(min_heap, num)
    else:
        if num < min_heap[0]:
            heapq.heappush(max_heap, -num)
        else:
            heapq.heappush(min_heap, num)
            heapq.heappush(max_heap, -heapq.heappop(min_heap))
    ans += str(-max_heap[0]) + '\n'
if n > 1:
    print(ans)
