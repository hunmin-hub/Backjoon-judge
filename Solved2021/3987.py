import sys
INF=99999999
input=sys.stdin.readline

N, M =map(int,input().rstrip().split(' '))
space_map=[]
for i in range(N):
    space_map.append(list(input().rstrip()))
start_x,start_y=map(int,input().rstrip().split(' '))

control={'U':(-1,0),"R":(0,1),"D":(1,0),'L':(0,-1)}

def shot_beam(x,y,command,count):
    while True:
        if count==N*M : return INF
        if x<0 or x==N or y<0 or y==M : return count
        if space_map[x][y]=='C': return count

        if space_map[x][y]=='/':
            px,py=command
            command=(-1*py,-1*px)
        elif space_map[x][y]=='\\':
            px,py=command
            command=(py,px)
        px,py=command
        x=x+px
        y=y+py
        count+=1

answer=(0,'X')
for key, command in control.items():
    result=shot_beam(start_x-1,start_y-1,command,0)
    if answer[0]<result:
        answer=(result,key)

if answer[0]==INF :
    print(answer[1])
    print("Voyager")
else :
    print(answer[1])
    print(answer[0])
