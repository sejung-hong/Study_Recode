//프로그래머스 전력망을 둘로 나누기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000001;
    //연결되어있는 노드 vec에 저장
    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < wires.size(); i++) {
        vec[wires[i][0]].push_back(wires[i][1]);
        vec[wires[i][1]].push_back(wires[i][0]);
    }

    //wires 하나씩 끊어보기
    for (int i = 0; i < wires.size(); i++) {
        int size = 0;
        //연결된 것이 하나인 노드일 때
        if (vec[wires[i][0]].size() == 1 || vec[wires[i][1]].size() == 1) {
            size = n - 2;
        }
        else {
            //BFS 깊이 우선 탐색
            queue<int> q;
            q.push(wires[i][0]);
            size++;
            //방문 노드 확인
            bool visited[101] = { 0, };
            visited[wires[i][0]] = true;
            visited[wires[i][1]] = true;
            while (!q.empty()) {
                for (int j = 0; j < vec[q.front()].size(); j++) {
                    //방문하지 않은 노드
                    if (visited[vec[q.front()][j]] == false) {
                        q.push(vec[q.front()][j]); //연결되어있는 노드 push
                        visited[vec[q.front()][j]] = true; //방문
                        size++;
                    }
                }
                q.pop();
            }
            size = abs(size - (n - size)); //절댓값
        }
        answer = min(answer, size); //최솟값
    }

    return answer;
}

int main() {
    int n = 9;
    vector<vector<int>> wires = { {1,3}, {2,3}, {3,4}, {4,5}, {4,6}, {4,7}, {7,8}, {7,9} };
    cout << solution(n, wires) << "\n";
    return 0;
}