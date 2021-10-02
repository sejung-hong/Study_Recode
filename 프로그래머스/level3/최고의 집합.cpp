//���α׷��ӽ� �ְ��� ����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    //������ ����� ���� ��
    if (n > s) {
        answer.push_back(-1);
        return answer;
    }
    
    int div = s / n; //��
    int namuji = s % n; //������

    //n���� ������ ���� �� ��ŭ
    for (int i = 0; i < n - namuji; i++) {
        answer.push_back(div);
    }
    //������ ������ŭ
    for (int i = 0; i < namuji; i++) {
        answer.push_back(div + 1);
    }

    return answer;
}

int main() {
    int n = 2;
    int s = 9;
    solution(n, s);
    return 0;
}