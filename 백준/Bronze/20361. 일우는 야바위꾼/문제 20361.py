n,x,k=map(int, input().split())
yabai=[0]*(n+1)
yabai[x]=1
for i in range(k):
    a,b=map(int,input().split())
    tmp=yabai[a]
    yabai[a]=yabai[b]
    yabai[b]=tmp
print(yabai.index(1))