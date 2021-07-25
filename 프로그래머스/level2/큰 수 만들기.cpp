//프로그래머스 큰 수 만들기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int idx = -1;
    for (int i = 0; i < number.size() - k; i++) {
        char max = ' ';
        for (int j = idx + 1; j <= k + i; j++) {
            if (max < number[j]) {
                max = number[j];
                idx = j;
            }
        }
        answer += max;
    }
    return answer;
}
int main() {
    string number = "1231234";
    int k = 3;
    cout << solution(number, k) << "\n";
    return 0;
}
