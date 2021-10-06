//���α׷��ӽ� �ܼ�ī�޶�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end()); //���� ���� ������ ����

    int temp = 30001;
    for (int i = 0; i < routes.size(); i++) {
        // ī�޶� �̵�
        if (temp > routes[i][1]) {
            temp = routes[i][1];
        }
        if (routes[i][0] > temp) {
            temp = routes[i][1]; //���ο� ī�޶� ��ġ
            answer++; //ī�޶� ��ġ
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> routes = { {-20,15}, {-14,-5}, {-18,-13}, {-5, -3} };
    cout << solution(routes) << "\n";
    return 0; 
}
