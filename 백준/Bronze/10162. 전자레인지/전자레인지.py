t = int(input())
a, b, c = 300, 60, 10
cnt_a = t // a; t -= cnt_a * a
cnt_b = t // b; t -= cnt_b * b
cnt_c = t // c; t -= cnt_c * c
print(cnt_a, cnt_b, cnt_c) if t == 0 else print(-1)