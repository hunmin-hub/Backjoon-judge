import sys
from collections import deque
input=sys.stdin.readline
INF_NUM=9999999
F,S,G,U,D=map(int,input().rstrip().split(' '))
jump_stair=[U,D*(-1)]
visit=[False]*(F+1)
dist=[INF_NUM]*(F+1)

v_queue=deque()
visit[S]=True
dist[S]=0
v_queue.append(S)
while len(v_queue)!=0 :
    current_v=v_queue.popleft()
    for idx in range(2):
        next_v=current_v+jump_stair[idx]
        if next_v<=0 or next_v>F : continue
        if visit[next_v]==False and dist[next_v]>dist[current_v]+1 :
            visit[next_v]=True
            dist[next_v]=dist[current_v]+1
            v_queue.append(next_v)

if dist[G]==INF_NUM :
    print("use the stairs")
else :
    print(dist[G])