def hanoi(n, start=1, by=2, end=3):
    if n==1:
        print(start, end)
        return
    
    hanoi(n-1, start, end, by)
    print(start, end)
    hanoi(n-1, by, start, end)

n = int(input())
print(2**n -1)
hanoi(n)