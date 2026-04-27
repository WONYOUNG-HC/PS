def fibonacci_repeat(n):
    if n==0:
        return 0
    if n==1:
        return 1
    
    list = [0,1]
    for i in range(n-1):
        list.append(list[-1] + list[-2])
    return list[-1]

n = int(input())
print(fibonacci_repeat(n))