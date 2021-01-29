def change_number(n,number) :
    target="0123456789ABCDEF"
    c_num=""
    if number==0 : return "0"
    while number>0 :
        c_num+=target[number%n]
        number//=n
    c_num=c_num[::-1]
    return c_num
def solution(n, t, m, p):
    answer = ''
    ordered_num=""
    i=0
    while len(ordered_num)<(t*m) :
        ordered_num+=change_number(n,i)
        i+=1
    for _ in range(t) :
        answer+=ordered_num[p-1]
        p+=m
    return answer