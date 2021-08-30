//프로그래머스 프렌즈4블록
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int ni[3] = { 0,1,1 }, nj[3] = { 1,0,1 };

//2x2형태인지 확인
bool Block4(int i, int j, vector<string>& board) {
    char c = board[i][j];
    if (c == '*')
        return false;
    for (int k = 0; k < 3; k++) {
        if (board[i + ni[k]][j + nj[k]] != c) {
            return false; //같지 않을 때
        }
    }
    return true;
}

//*로 변경
void Change(int i, int j, vector<string>& board) {
    board[i][j] = '*';
    for (int k = 0; k < 3; k++) {
        board[i + ni[k]][j + nj[k]] = '*';
    }
}

//밑으로 내리기
void Down(int m, int n, vector<string>& board) {
    for (int i = 0; i < n; i++) { // 폭
        for (int j = m - 1; j > 0; j--) { //높이
            if (board[j][i] == '*') {
                for (int k = j - 1; k >= 0; k--) {
                    if (board[k][i] != '*') {
                        board[j][i] = board[k][i];
                        board[k][i] = '*';
                        break;
                    }
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    queue<pair<int, int>> q;
    while(1) {
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (Block4(i, j, board)) {
                    q.emplace(i, j);
                }
            }
        }
        //더이상 지워질 블럭이 없을때
        if (q.empty())
            break;

        while(!q.empty()) {
            Change(q.front().first, q.front().second, board);
            q.pop();
        }

        Down(m, n, board); //떨어지기
    }
    //지워진 블록 개수
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '*')
                answer++;
        }
    }

    return answer;
}

int main() {
    int m = 6;
    int n = 6;
    vector <string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    cout << solution(m, n, board) << endl;
    return 0;
}