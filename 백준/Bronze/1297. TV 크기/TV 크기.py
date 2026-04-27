d, h, w = map(int, input().split())
r = (d**2 / (h**2 + w**2)) ** 0.5
print(int(h*r), int(w*r))