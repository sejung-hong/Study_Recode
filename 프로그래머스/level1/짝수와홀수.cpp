//프로그래머스 짝수와 홀수
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if (num % 2 == 0) {
        answer = "Even";
    }
    else {
        answer = "Odd";
    }
    return answer;
}

int main() {
    int num = 3;
    cout << solution(num) << "\n";
    return 0;
}