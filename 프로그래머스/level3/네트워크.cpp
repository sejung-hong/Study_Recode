//프로그래머스 네트워크
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> computers_copy;
bool visited[201] = { false, };

void DFS(int node) {
    visited[node] = true; //방문한 노드
    for (int i = 0; i < computers_copy.size(); i++) {
        if (visited[i] == false) {
            if (computers_copy[node][i] == 1) {
                DFS(i);
            }
        }
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    computers_copy = computers; //전역변수
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            DFS(i);
            answer++;
        }
    }

    return answer;
}

int main() {
    int n = 3;
    vector<vector<int>> computers = { {1,1,0}, {1,1,1}, {0,1,1} };
    cout << solution(n, computers) << "\n";

    return 0;
}