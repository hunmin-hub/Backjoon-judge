import sys
input=sys.stdin.readline
global answer
answer=0
N=int(input().rstrip())
damage_list=list(map(int,input().rstrip().split(' ')))
happy_list=list(map(int,input().rstrip().split(' ')))

def DFS(vertex,life,happy):
    if life<=0 : return
    if vertex==N-1 :
        global answer
        if answer<happy :
            answer=happy
        return
    DFS(vertex+1,life-damage_list[vertex+1],happy+happy_list[vertex+1])
    DFS(vertex+1,life,happy)
    return

DFS(-1,100,0)
print(answer)