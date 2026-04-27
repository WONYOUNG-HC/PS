import sys

nums = list(map(int, sys.stdin.readline().split()))
while nums[0] != 0:
    nums.sort()
    if nums[0]**2 + nums[1]**2 == nums[2]**2:
        print('right')
    else:
        print('wrong')
    nums = list(map(int, sys.stdin.readline().split()))
