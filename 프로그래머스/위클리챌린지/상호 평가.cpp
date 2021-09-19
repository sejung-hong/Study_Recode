//���α׷��ӽ� ��ȣ ��
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int n = scores.size();

    for (int i = 0; i < n; i++) {
        int min_ = 101;
        int max_ = -1;
        double sum = 0;
        double num = n;
        map <int, int> m;

        for (int j = 0; j < n; j++) {
            sum += scores[j][i];
            min_ = min(scores[j][i], min_); //������
            max_ = max(scores[j][i], max_); //�ְ���
            m[scores[j][i]]++;
        }


        //�ڱ� �ڽ��� ���� ������ ������ �ְ��� �Ǵ� �������� ��
        if (min_ == scores[i][i] || max_ == scores[i][i]) {
            if (m[scores[i][i]] == 1) { //�������� �Ǵ�
                sum -= scores[i][i];
                num--;
            }
        }

        double avr = sum / num; //���
        
        if (avr >= 90) answer += 'A';
        else if (avr < 90 && avr >= 80) answer += 'B';
        else if (avr < 80 && avr >= 70) answer += 'C';
        else if (avr < 70 && avr >= 50) answer += 'D';
        else answer += 'F';

    }
    return answer;
}

int main() {
    vector<vector<int>> secores = { {100,90,98,88,65} ,{50,45,99,85,77},{47,88,95,80,67},{61,57,100,80,65},{24,90,94,75,65} };
    cout << solution(secores) << "\n";
    return 0;
}