import sys
from collections import defaultdict
input=sys.stdin.readline
vocab=defaultdict(int)
key=input().rstrip()
len_key=len(key)
Dy=[0]*len_key

if len_key>=2 :
    if key[0]!='0' : Dy[0]=1
    if key[1]!='0' : Dy[1]=1
    check_key=int(key[0]+key[1])
    if key[0]!='0' and check_key>=1 and check_key<=26 : Dy[1]+=1
    for i in range(2,len_key):
        check_key=int(key[i])
        if check_key>=1 and check_key<=26 : Dy[i]+=Dy[i-1]
        check_key=int(key[i-1]+key[i])
        if key[i-1]!='0' and check_key>=1 and check_key<=26 : Dy[i]+=Dy[i-2]
else :
    if key[0]!='0' : Dy[0]=1

print(Dy[len_key-1]%1000000)


