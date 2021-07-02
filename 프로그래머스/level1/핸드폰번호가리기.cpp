//프로그래머스 핸드폰 번호 가리기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for (int i = 0; i < phone_number.size() - 4; i++) {
        answer += "*";
    }
    for (int i = phone_number.size() - 4; i < phone_number.size(); i++) {
        answer += phone_number[i];
    }
    return answer;
}

int main() {
    string phone_number = "01033334444";
    cout << solution(phone_number) << "\n";
    return 0;
}