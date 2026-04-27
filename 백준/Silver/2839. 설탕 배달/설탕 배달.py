n = int(input())
five = n // 5
while five >= 0:
    if (n - five*5) % 3 == 0:
        print(five + (n - five*5)//3)
        break
    else:
        five -= 1
if five < 0:
    print(-1)
