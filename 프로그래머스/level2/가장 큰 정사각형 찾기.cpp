//프로그래머스 가장 큰 정사각형 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            if (board[i][j] == 1) {
                board[i][j] = min({ board[i - 1][j - 1], board[i - 1][j], board[i][j - 1] }) + 1; //왼쪽위 대각선, 왼쪽, 위 방향중 가장 작은 값
                answer = max(answer, board[i][j]); //배열 중 가장 큰 값
            }
        }
    }

    return answer * answer; //정사각형 사이즈
}
int main() {
    vector<vector<int>> board = { {0,1,1,1}, {1,1,1,1},{1,1,1,1}, {0,0,1,0} };
    cout << solution(board) << "\n";
    return 0;
}