#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int board[7][7] = { 0, };
int visited[7][7] = { 0, };
int ni[4] = { 1,0,-1,0 }, nj[4] = { 0,1,0,-1 };
vector<vector<int>> pang;
map<int, int> M;

void DFS(int i, int j, int color) {
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int next_i = ni[i] + i;
        int next_j = nj[i] + j;
        if (next_i > 6 || next_j > 6 || next_i <= 0 || next_j <= 0)
            continue;
        if (board[next_i][next_j] == color && visited[next_i][next_j] == false){
            DFS(next_i, next_j, color);
            vector<int> temp;
            temp.push_back(next_i); temp.push_back(next_j);
            pang.push_back(temp);
        }
    }

}

void Change() {
    for (int i = 0; i < pang.size(); i++) {
        board[pang[i][0]][pang[i][1]] = 0;
    }
    pang.clear();
}

void Down() {
    for (int i = 0; i < 6; i++) {
        for (int j = 5; j > 0; j--) {
            if (board[j][i] == ' ') {
                for (int k = j - 1; k >= 0; k--) {
                    if (board[k][i] != 0) {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
}

vector<string> solution(vector<vector<int>> macaron) {
    vector<string> answer;

    for (int i = 0; i < macaron.size(); i++) {
        for (int j = 5; j >= 0; j--) {
            if (board[j][macaron[i][0]] == 0) {
                board[j][macaron[i][0]] = macaron[i][1]; //¸¶Ä«·Õ ¶³¾î¶ß¸®±â
                M[macaron[i][1]]++;
                DFS(j, macaron[i][0], macaron[i][1]);
                if (pang.size() >= 3) {
                    M[macaron[i][1]] -= pang.size();
                    Change();
                    Down();
                }
                break;
            }
        }

        int check = 0;
        for (auto v : M) {
            if (v.second > 2) {
                check = 1;
                break;
            }
        }
        if (check == 1) {
            for (int m = 0; m < 6; m++) {
                for (int n = 0; n < 6; n++) {
                    if (board[m][n] != 0) {
                        DFS(m, n, board[m][n]);
                        if (pang.size() >= 3) {
                            Change();
                            Down();
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        string s = "";
        for (int j = 0; j < 6; j++) {
            s += to_string(board[i][j]);
        }
        answer.push_back(s);
    }

    return answer;
}

int main() {
    vector<vector<int>> macaron = { {1,1}, {2,1}, {1,2}, {3,3}, {6,4}, {3,1}, {3,3}, {3,3}, {3,4}, {2,1} };
    solution(macaron);
    return 0;
}