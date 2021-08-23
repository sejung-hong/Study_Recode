//프로그래머스 섬 연결하기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool visited[101] = { false, };

bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);

    //가장 작은 간선 선택
    visited[costs[0][0]] = true;
    visited[costs[0][1]] = true;
    answer += costs[0][2];

    int count = 2; //연결된 노드 두개

    while (1) {
        for (int i = 1; i < costs.size(); i++) {
            if (visited[costs[i][0]] ^ visited[costs[i][1]]) {
                //연결된 노드
                visited[costs[i][0]] = true;
                visited[costs[i][1]] = true;
                answer += costs[i][2];
                count++;
                break;
            }
        }
        if (count == n) {
            break;
        }
    }

    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> costs = { {0,1,1}, {0,2,2}, {1,2,1},{1,3,3}, {2,3,8},{3,4,1} };
    cout << solution(n, costs) << "\n";
    return 0;
}