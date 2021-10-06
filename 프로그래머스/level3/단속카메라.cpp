//프로그래머스 단속카메라
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end()); //빨리 들어가는 순으로 정렬

    int temp = 30001;
    for (int i = 0; i < routes.size(); i++) {
        // 카메라 이동
        if (temp > routes[i][1]) {
            temp = routes[i][1];
        }
        if (routes[i][0] > temp) {
            temp = routes[i][1]; //새로운 카메라 위치
            answer++; //카메라 설치
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> routes = { {-20,15}, {-14,-5}, {-18,-13}, {-5, -3} };
    cout << solution(routes) << "\n";
    return 0; 
}
