//프로그래머스 가장 먼 노드
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool graph[20001][20001] = { false, };
int visited[20001] = { 0, };

void BFS(int n) {
    visited[1] = 1;
    
    queue <int> q;
    q.push(1);

    while (!q.empty()) {
        for (int i = 2; i <= n; i++) {
            if (graph[q.front()][i] != false && visited[i] == 0) {// next로 갈 수 있을 때
                q.push(i);
                visited[i] = visited[q.front()] + 1;
            }
        }
        q.pop();
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]][edge[i][1]] = true;
        graph[edge[i][1]][edge[i][0]] = true;
    } //graph 구성

    BFS(n);

    int max_distance = 0;
    for (int i = 2; i <= n; i++) {
        if (visited[i] > max_distance) {
            max_distance = visited[i];
            answer = 1;
        }
        else if (visited[i] == max_distance) {
            answer++;
        }

    }

    return answer;
}

int main() {
    int n = 6;
    vector<vector<int>> edge = { {3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2} };
    cout << solution(n, edge) << "\n";
    return 0;
}