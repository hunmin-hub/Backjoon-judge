import sys
input=sys.stdin.readline
N=int(input().rstrip())
words=["sukhwan","baby","sukhwan","tururu","turu","very","cute","tururu","turu","in","bed","tururu","turu","baby"]

loof=N//14
idx=N%14
if idx==0 : loof-=1
target=words[idx]
if loof>=1 and "turu" in target :
    for _ in range(loof): 
        target+="ru"
    temp=target.count("ru")
    if temp>=5 :
        target=f'tu+ru*{temp}'

print(target)