from collections import defaultdict
from itertools import combinations
def create_dict(relation,idx):
    db_dict=defaultdict(int)
    for i in range(0,len(relation)):
        temp=""
        for x in idx :
            temp+=relation[i][x]
            temp+=str(x)
        db_dict[temp]+=1
        if db_dict[temp]>1 :
            return False
    return True

def solution(relation):
    answer = 0
    key_set=[]
    column=[x for x in range(0,len(relation[0]))]
    for i in range(1,len(relation[0])+1) :
        idx=list(combinations(column,i))
        for sets in idx :
            if create_dict(relation,list(sets)) :
                key_set.append(set(sets))
    
    for current_set in key_set[:] :
        for next_set in key_set[:] :
            if current_set==next_set :
                continue
            if current_set==current_set&next_set :
                key_set.remove(next_set)
    answer=len(key_set)
    return answer