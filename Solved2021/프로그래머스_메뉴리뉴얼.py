from collections import defaultdict
course_menu=defaultdict(int)
course_count=defaultdict(int)
def combine_menu(order_menu,vertex,menu) :
    if vertex==len(order_menu) :
        if len(menu)>=2 :
            temp=list(menu)
            temp.sort()
            course_menu[''.join(temp)]+=1
        return
    combine_menu(order_menu,vertex+1,menu+order_menu[vertex])
    combine_menu(order_menu,vertex+1,menu)
    
def solution(orders, course):
    answer = []
    for order in orders :  
        combine_menu(order,0,"")
    survey_menu=sorted(course_menu.items(),key=lambda x:len(x[0]),reverse=True)
    for x in survey_menu :
        menu_name, menu_count=x
        if len(menu_name) in course and menu_count>=2 :
            if course_count[len(menu_name)]<menu_count :
                course_count[len(menu_name)]=menu_count
    for x in course_count.items() :
        list_len, list_count=x
        for items in survey_menu :
            menu_name, menu_count=items
            if list_len==len(menu_name) and list_count==menu_count :
                answer.append(menu_name)
    answer.sort()
    return answer
