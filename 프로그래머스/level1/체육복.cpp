//���α׷��ӽ� ü����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            vector <int> ::iterator it;
            it = find(reserve.begin(), reserve.end(), lost[i]);
            //�Ҿ���� �л��� ������ �������� ��
            if (it != reserve.end()) {
                reserve.erase(it);
                lost.erase(lost.begin() + i);
                i--;
                answer++;
                break;
            }
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            vector <int> ::iterator it;
            it = find(reserve.begin(), reserve.end(), lost[i]-1);
            //�Ҿ���� �л��� �� ��ȣ �л��� ������ �������� ��
            if (it != reserve.end()) {
                reserve.erase(it);
                answer++;
                break;
            }
            it = find(reserve.begin(), reserve.end(), lost[i] + 1);
            //�Ҿ���� �л��� �� ��ȣ �л��� ������ �������� ��
            if (it != reserve.end()) {
                reserve.erase(it);
                answer++;
                break;
            }
        }
    }

    return answer;
}
*/

//������ Ǯ��
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[35] = { 0, };
    for (int i : reserve) student[i] += 1;
    for (int i : lost) student[i] += -1;
    for (int i = 1; i <= n; i++) {
        if (student[i] == -1) {
            if (student[i - 1] == 1) {
                student[i - 1] = 0;
                student[i] = 0;
            }
            else if (student[i + 1] == 1) {
                student[i + 1] = 0;
                student[i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (student[i] != -1) answer++;
    }

    return answer;
}



int main() {
    int n = 5;
    vector <int> lost = { 2,4 };
    vector <int> reserve = { 1,3,5 };

    cout << solution(n, lost, reserve) << "\n";

    return 0;
}