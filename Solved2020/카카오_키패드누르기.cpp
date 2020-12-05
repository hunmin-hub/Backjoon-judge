#include <string>
#include <vector>

using namespace std;

char select_hand(int c_left_x, int c_left_y, int c_right_x, int c_right_y, int sx, int sy, string hand) {
    char rhand;
    if (hand == "L") rhand = 'L';
    else rhand = 'R';
    int left_dis = abs(c_left_x - sx) + abs(c_left_y - sy);
    int right_dis = abs(c_right_x - sx) + abs(c_right_y - sy);
    if (left_dis > right_dis) return 'R';
    else if (left_dis < right_dis) return 'L';
    else return rhand;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";

    if (hand.compare("right")==0) {
        hand = "R";
    }
    else {
        hand = "L";
    }

    int c_right_x = 3, c_right_y = 4; // ������ �ʱ� ��ġ "#"
    int c_left_x = 1, c_left_y = 4; // �޼� �ʱ� ��ġ "*"
    for (int i = 0; i < numbers.size(); i++) {
        printf("�� %d %d\n", c_left_x, c_left_y);
        printf("�� %d %d\n", c_right_x, c_right_y);
        if (numbers[i] == 1) { // �޼�
            c_left_x = 1; c_left_y = 1;
            answer.push_back('L');
        }
        else if (numbers[i] == 4) { //�޼�
            c_left_x = 1; c_left_y = 2;
            answer.push_back('L');
        }
        else if (numbers[i] == 7) { //�޼�
            c_left_x = 1; c_left_y = 3;
            answer.push_back('L');
        }
        else if (numbers[i] == 3) { //������
            c_right_x = 3; c_right_y = 1;
            answer.push_back('R');
        }
        else if (numbers[i] == 6) { //������
            c_right_x = 3; c_right_y = 2;
            answer.push_back('R');
        }
        else if (numbers[i] == 9) { //������
            c_right_x = 3; c_right_y = 3;
            answer.push_back('R');
        }
        else if (numbers[i] == 2) { // �ǵ��ʿ�
            // 2 ��ǥ (1,2)
            answer.push_back(select_hand(c_left_x, c_left_y, c_right_x, c_right_y, 2, 1, hand));
            if (answer.back() == 'R') {
                c_right_x = 2; c_right_y = 1;
            }
            else {
                c_left_x = 2; c_left_y = 1;
            }
        }
        else if (numbers[i] == 5) { // �ǵ��ʿ�
            // 5 ��ǥ (2,2)
            answer.push_back(select_hand(c_left_x, c_left_y, c_right_x, c_right_y, 2, 2, hand));
            if (answer.back() == 'R') {
                c_right_x = 2; c_right_y = 2;
            }
            else {
                c_left_x = 2; c_left_y = 2;
            }
        }
        else if (numbers[i] == 8) { // �ǵ��ʿ�
            // 8 ��ǥ (3,2)
            answer.push_back(select_hand(c_left_x, c_left_y, c_right_x, c_right_y, 2, 3, hand));
            if (answer.back() == 'R') {
                c_right_x = 2; c_right_y = 3;
            }
            else {
                c_left_x = 2; c_left_y = 3;
            }
        }
        else if (numbers[i] == 0) { // �ǵ��ʿ�
            // 0 ��ǥ (4,2)
            answer.push_back(select_hand(c_left_x, c_left_y, c_right_x, c_right_y, 2, 4, hand));
            if (answer.back() == 'R') {
                c_right_x = 2; c_right_y = 4;
            }
            else {
                c_left_x = 2; c_left_y = 4;
            }
        }
    }
    return answer;
}
int main() {
    vector<int> a;
    string b="";
    a.push_back(7);
    a.push_back(0);
    a.push_back(8);
    a.push_back(2);
    a.push_back(8);
    a.push_back(3);
    a.push_back(1);
    a.push_back(5);
    a.push_back(7);
    a.push_back(6);
    a.push_back(2);
    b=solution(a, "left");
    for (int i = 0; i < b.size(); i++) {
        printf("%c", b[i]);
    }
    return 0;
}