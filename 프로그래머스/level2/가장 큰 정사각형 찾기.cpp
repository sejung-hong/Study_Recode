//���α׷��ӽ� ���� ū ���簢�� ã��
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
                board[i][j] = min({ board[i - 1][j - 1], board[i - 1][j], board[i][j - 1] }) + 1; //������ �밢��, ����, �� ������ ���� ���� ��
                answer = max(answer, board[i][j]); //�迭 �� ���� ū ��
            }
        }
    }

    return answer * answer; //���簢�� ������
}
int main() {
    vector<vector<int>> board = { {0,1,1,1}, {1,1,1,1},{1,1,1,1}, {0,0,1,0} };
    cout << solution(board) << "\n";
    return 0;
}