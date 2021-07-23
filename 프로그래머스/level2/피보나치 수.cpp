//프로그래머스 피보나치 수
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int fivo[100001];
    fivo[0] = 0;
    fivo[1] = 1;

    for (int i = 2; i <= n; i++) {
        fivo[i] = (fivo[i - 1] + fivo[i - 2]) % 1234567;
    }

    answer = fivo[n];

    return answer;
}

int main() {
    int n = 3;
    cout << solution(n) << "\n";

    return 0;
}