//프로그래머스 거리두기 확인하기
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector <string> place;
int visited[5][5] = { 0, };

int ni[4] = { 1, 0, -1, 0 };
int nj[4] = { 0, 1, 0, -1 };

int BFS(int i, int j) {
    visited[i][j] = 1;
    queue <pair<int, int>> q; //위치 쌍으로 저장
    q.emplace(i, j);

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        if (visited[i][j] > 4) {
            return true;
        }
        for (int x = 0; x < 4; x++) {
            int next_i = i + ni[x];
            int next_j = j + nj[x];
            if (next_i < 0 || next_j < 0 || next_i >= 5 || next_j >= 5) {
                continue;
            }
            if (visited[next_i][next_j] == 0 && place[next_i][next_j] != 'X') {
                q.emplace(next_i, next_j);
                visited[next_i][next_j] = visited[i][j] + 1;
                if (place[next_i][next_j] == 'P' && visited[next_i][next_j] < 4) {
                    return false;
                }
            }
        }
        q.pop();
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {
        place = places[i];
        int check = true;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                //응사자가 앉아있는 자리 이고 방문하지 않았을 때
                memset(visited, 0, sizeof(visited)); //0으로 초기화
                if (place[i][j] == 'P') {
                    check = BFS(i, j);
                    if (check == false)
                        break;
                    
                }
            }
            if (check == false)
                break;
        }
        if (check == false) {
            answer.push_back(0);
        }
        else {
            answer.push_back(1);
        }
    }

    return answer;
}

int main() {
    vector<vector<string>> places =
    { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
      {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
      {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
      {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
      {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };
    solution(places);

    return 0;
}