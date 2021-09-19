//프로그래머스 상호 평가
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
            min_ = min(scores[j][i], min_); //최저점
            max_ = max(scores[j][i], max_); //최고점
            m[scores[j][i]]++;
        }


        //자기 자신을 평가한 점수가 유일한 최고점 또는 최저점일 때
        if (min_ == scores[i][i] || max_ == scores[i][i]) {
            if (m[scores[i][i]] == 1) { //유일한지 판단
                sum -= scores[i][i];
                num--;
            }
        }

        double avr = sum / num; //평균
        
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