//프로그래머스 숫자의 표현
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += j; //수 더하기
            if (sum == n) {
                answer++; //증가
                break;
            }
            else if (sum > n)
                break;
        }
    }
    return answer;
}

int main() {
    int n = 15;
    cout << solution(n) << "\n";
    return 0;
}