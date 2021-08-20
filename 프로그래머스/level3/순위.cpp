//프로그래머스 순위
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    int graph[101][101] = { false, };

    for (int i = 0; i < results.size(); i++) {
        graph[results[i][0]][results[i][1]] = 1; // graph 생성
    }

    //floyd warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) { //graph[i][j] : win, graph[j][i] : lose
                count++;
            }
        }
        if (count == n - 1) { //자기 자신을 제외한 모든 사람의 우위를 가릴 수 있음
            answer++;
        }
    }


    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> results = { {4,3}, {4,2}, {3,2}, {1,2}, {2,5} };
    cout << solution(n, results) << "\n";
    return 0;
}

