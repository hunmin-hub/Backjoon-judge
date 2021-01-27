from collections import defaultdict
import bisect
 
info_dict=defaultdict(lambda:defaultdict(lambda:defaultdict(lambda:defaultdict(list))))
# dict[lang][position][level][food].append(score)
def solution(info, query):
    answer = []
    info_list=[]
    for user_info in info :
        info_list.append(user_info.split(' '))
    info_list=sorted(info_list,key=lambda x:int(x[4]))
    for user_info in info_list :
        info_lang,info_position,info_level,info_food,info_score=map(str,user_info)
        ## info push 16
        info_dict[info_lang][info_position][info_level][info_food].append(int(info_score)) #0000
        info_dict["-"][info_position][info_level][info_food].append(int(info_score)) #1000
        info_dict["-"]["-"][info_level][info_food].append(int(info_score)) #1100
        info_dict["-"]["-"]["-"][info_food].append(int(info_score)) #1110
        info_dict["-"]["-"]["-"]["-"].append(int(info_score)) #1111     
        info_dict["-"][info_position]["-"][info_food].append(int(info_score)) #1010
        info_dict["-"][info_position]["-"]["-"].append(int(info_score)) #1011
        info_dict["-"][info_position][info_level]["-"].append(int(info_score)) #1001
        info_dict["-"]["-"][info_level]["-"].append(int(info_score)) #1101   
        info_dict[info_lang]["-"]["-"][info_food].append(int(info_score)) #0110
        info_dict[info_lang]["-"]["-"]["-"].append(int(info_score)) #0111
        info_dict[info_lang]["-"][info_level]["-"].append(int(info_score)) #0101
        info_dict[info_lang][info_position]["-"]["-"].append(int(info_score)) #0011   
        info_dict[info_lang]["-"][info_level][info_food].append(int(info_score)) #0100
        info_dict[info_lang][info_position]["-"][info_food].append(int(info_score)) #0010
        info_dict[info_lang][info_position][info_level]["-"].append(int(info_score)) #0001
    
    for x in query :
        find_lang,trash1,find_position,trash2,find_level,trash3,find_food,find_score=map(str,x.split(' '))
        temp_len=len(info_dict[find_lang][find_position][find_level][find_food])
        find_len=bisect.bisect_left(info_dict[find_lang][find_position][find_level][find_food],
                                    int(find_score))
        answer.append(temp_len-find_len)
    return answer
