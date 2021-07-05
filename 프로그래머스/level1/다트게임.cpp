//프로그래머스 다트게임
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> digit;

    string num;
    int n = 0;

    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] == 'S') {
            n = stoi(num);
            digit.push_back(n);
            num = "";
        }
        else if (dartResult[i] == 'D') {
            n = pow(stoi(num), 2); //제곱
            digit.push_back(n);
            num = "";
        }
        else if (dartResult[i] == 'T') {
            n = pow(stoi(num), 3); //세제곱
            digit.push_back(n);
            num = "";
        }
        else if (dartResult[i] == '*') {
            digit[digit.size() - 1] *= 2;
            if (digit.size() != 1) {
                digit[digit.size() - 2] *= 2;
            }
        }
        else if (dartResult[i] == '#') {
            digit[digit.size() - 1] *= -1;
        }
        else {
            num += dartResult[i]; 
        }
    }

    for (int i = 0; i < digit.size(); i++) {
        answer += digit[i];
    }

    return answer;
}

int main() {
    string s = "1D2S3T*";

    cout << solution(s) << "\n";

    return 0;
}