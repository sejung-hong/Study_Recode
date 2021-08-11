//프로그래머스 배달
#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 1;
    int road_network[51][51] = { 0, };
    bool visited[51] = { false, };
    visited[1] = true;
    for (int i = 0; i < road.size(); i++) {
        if (road_network[road[i][0]][road[i][1]] != 0) {
            if (road_network[road[i][0]][road[i][1]] < road[i][2]) {
                continue;
            }
        }
        road_network[road[i][0]][road[i][1]] = road[i][2];
        road_network[road[i][1]][road[i][0]] = road[i][2];
    } //도로 네트워크 생성

    for (int j = 1; j <= N; j++) {
        int min = 1000000;
        int idx = 0;
        for (int i = 1; i <= N; i++) {
            if (visited[i] == false && min > road_network[1][i] && road_network[1][i] != 0) {
                min = road_network[1][i];
                idx = i;
            }
        }
        visited[idx] = true;
        for (int i = 1; i <= N; i++) {
            if (visited[i] == false && road_network[idx][i] != 0) {
                if (road_network[idx][i] + road_network[1][idx] < road_network[1][i] || road_network[1][i] == 0) {
                    road_network[1][i] = road_network[idx][i] + road_network[1][idx];
                }
            }
        }
    }


    for (int i = 2; i <= N; i++) {
        if (road_network[1][i]<= K) {
            answer++;
        }//배달 가능한 마을
    }

    return answer;
}

int main() {
    int N = 6;
    vector<vector<int>> road = { {1,2,1}, {1,3,2}, {2,3,2}, {3,4,3}, {3,5,2}, {3,5,3},{5,6,1} };
    int K = 4;
    cout << solution(N, road, K) << "\n";
    return 0;
}
