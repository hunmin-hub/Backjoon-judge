import sys
input=sys.stdin.readline
global answer
answer=0
def word_combine(vertex,sentence) :
    if len(sentence) == 26:
        global answer
        answer += 2 ** (N - vertex-1)
        return
    if vertex>=0 and len(sentence)+word_len[vertex]<26 :
        return
    if vertex==N-1 :
        return
    word_combine(vertex+1,sentence|word_list[vertex])
    word_combine(vertex+1,sentence)

N=int(input().rstrip())
word_list=[set(input().rstrip()) for x in range(N)]
word_len=[len(sets) for sets in word_list]
for i in range(N-2,-1,-1) :
    word_len[i]+=word_len[i+1]
word_combine(-1,set())
print(answer)