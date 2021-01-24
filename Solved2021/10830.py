import sys
import copy
def multiple_matrix(A,B) :
    # 행렬 A,B 곱
    C=[]
    for i in range(N) :
        temp_list = []
        for j in range(N) :
            temp=0
            for k in range(N) :
                temp+=int(A[i][k])*int(B[k][j])
            temp_list.append(temp%1000)
        C.append(temp_list)
    return C

def ten_to_two(num) :
    # 10진수 -> 2진수
    temp=[]
    while num>0 :
        temp.append(num%2)
        num//=2
    temp.reverse()
    return temp

def solution(A,calc_matrix,target_num) :
    result_matrix=multiple_matrix(calc_matrix,calc_matrix)
    if target_num==1 :
        result_matrix=multiple_matrix(result_matrix,A)
    return result_matrix

input=sys.stdin.readline
N,M=map(int,input().rstrip().split(' '))
A_matrix=[]
for _ in range(0,N) :
    A_matrix.append(list(map(int,(input().rstrip().split(' ')))))
M_two_arr=ten_to_two(M)
Next_matrix=copy.deepcopy(A_matrix)
for i in range(1,len(M_two_arr)) :
    Next_matrix=solution(A_matrix,Next_matrix,M_two_arr[i])

for line_matrix in Next_matrix :
    for x in line_matrix :
        print(x%1000,end=' ')
    print()