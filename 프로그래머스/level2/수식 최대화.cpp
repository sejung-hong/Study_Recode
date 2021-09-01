//프로그래머스 수식 최대화
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //절대값
#include <algorithm>

using namespace std;

vector<vector<string>> operation = { {"*", "+", "-"},{"*", "-", "+"}, {"+", "*", "-"}, {"+", "-", "*"}, {"-", "*", "+"}, {"-", "+", "*"} };

long long solution(string expression) {
    long long answer = 0;

    //vector v에 숫자와 연산 push
    vector <string> v; 
    string num = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            num += expression[i];
        }
        else {
            v.push_back(num); //수
;           num = expression[i];
            v.push_back(num); //문자
            num = "";
        }
    }
    v.push_back(num); //마지막 수

    vector<long long> answer_list;
    for (int i = 0; i < 6; i++) { //조합 6개
        vector <string> vec;
        vec = v;
        for (int j = 0; j < 3; j++) { //문자 우선 순위
            while (find(vec.begin(), vec.end(), operation[i][j]) !=vec.end()) {
                auto it = find(vec.begin(), vec.end(), operation[i][j]);

                //연산
                long long n;
                if (operation[i][j] == "*") {
                    n = stoll(vec[it - vec.begin() - 1]) * stoll(vec[it - vec.begin() + 1]);
                }
                else if (operation[i][j] == "+") {
                    n = stoll(vec[it - vec.begin() - 1]) + stoll(vec[it - vec.begin() + 1]);
                }
                else {
                    n = stoll(vec[it - vec.begin() - 1]) - stoll(vec[it - vec.begin() + 1]);
                }
                vec[it - vec.begin() - 1] = to_string(n); //연산 
                vec.erase(it, it + 2); // 문자 삭제
            }
        }
        answer = max(answer, abs(stoll(vec[0]))); //최대값 찾기
    }

    return answer;
}

int main() {
    string expression = "100-200*300-500+20";
    cout << solution(expression) << "\n";
    return 0;
}