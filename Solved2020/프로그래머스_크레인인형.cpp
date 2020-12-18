#include <string>
#include <vector>

using namespace std;
vector<int> out_board;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int check;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            check = board[j][moves[i] - 1];
            if (check != 0) {
                board[j][moves[i] - 1] = 0;
                if (!out_board.empty()) {
                    if (out_board.back() == check) {
                        answer += 2;
                        out_board.pop_back();
                        break;
                    }
                }
                out_board.push_back(check);
                break;
            }
        }
    }
    return answer;
}