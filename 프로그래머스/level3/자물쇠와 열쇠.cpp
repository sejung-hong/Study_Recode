//프로그래머스 자물쇠와 열쇠
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <sstream>

using namespace std;

//시계방향 90도 회전
void rotation(vector<vector<int>>& key) {
    vector <vector<int>> key_rotation;
    for (int i = 0; i < key.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < key.size(); j++) {
            temp.push_back(key[key.size() - j - 1][i]);
        }
        key_rotation.push_back(temp);
    }
    key = key_rotation;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    map<string, int> blank; //Lock에서 비워져있는 위치
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (lock[i][j] == 0) {
                string s = "";
                s += to_string(i);
                s += " "; //" "로 구분
                s += to_string(j);
                blank[s]++; //해쉬에 blank 위치 저장
            }
        }
    }
    
    //lock에 홈이 없을때
    if (blank.empty())
        return true;

    for (int k = 0; k < 4; k++) { //90도 회전
        //key의 돌기부분 vector에 쌍으로 저장
        vector<pair<int, int>> block;
        for (int i = 0; i < key.size(); i++) {
            for (int j = 0; j < key.size(); j++) {
                if (key[i][j] == 1) {
                    block.push_back(make_pair(i, j));
                }
            }
        }

        //lock 홈 부분
        for (auto m : blank) {
            //key 돌기 부분
            for (int n = 0; n < block.size(); n++) {
                stringstream ss(m.first);
                int col, row;
                ss >> col >> row;
                col = block[n].first - col;
                row = block[n].second - row; 
                //key의 돌기부분을 lock의 홈부분으로 이동
                int check = 0; //lock의 홈부분이 모두 채워졌는지 확인
                //모든 key의 돌기부분을 이동
                for (int x = 0; x < block.size(); x++) {
                    int col_b = block[x].first - col;
                    int row_b = block[x].second - row;
                    //key의 돌기가 이동한 위치가 lock의 위치를 벗어났을때
                    if (col_b >= lock.size() || row_b >= lock.size() || col_b < 0 || row_b < 0) {
                        continue;
                    }
                    //lock의 홈부분일 때
                    if (lock[col_b][row_b] == 0)
                        check++;
                    else
                        break;
                }
                //빈칸이 모두 채워졌을 때
                if (check == blank.size())
                    return true;
            }
        }
        rotation(key); //90도 회전
    }

    return answer;
}

int main() {
    vector<vector<int>> key = { {0,0,0}, {1,0,0}, {0,1,1} };
    vector<vector<int>> lock = { {1,1,1}, {1,1,0}, {1,0,1} };
    cout << solution(key, lock) << "\n";
    return 0;
}