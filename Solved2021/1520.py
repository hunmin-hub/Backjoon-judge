import sys
from collections import deque
input=sys.stdin.readline
px=[1,-1,0,0]
py=[0,0,1,-1]
N,M=map(int,input().rstrip().split(' '))
height=[]
Dy=[[-1]*M for _ in range(N)]

for _ in range(N):
    height.append(list(map(int,input().rstrip().split(' '))))

def searching(x,y):
    if x==N-1 and y==M-1 :
        return 1
    
    if Dy[x][y]==-1 :
        Dy[x][y]=0
        for idx in range(4) :
            n_x=x+px[idx]
            n_y=y+py[idx]
            if n_x>=0 and n_x<N and n_y>=0 and n_y<M:
                if height[x][y]>height[n_x][n_y] :
                    Dy[x][y]+=searching(n_x,n_y)
    return Dy[x][y]

print(searching(0,0))




