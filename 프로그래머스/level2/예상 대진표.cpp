//프로그래머스 예상 대진표
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int num = 2;
    int min_a_b = min(a, b);
    int max_a_b = max(a, b);

    while (1) {
        if ((max_a_b - 1) / num == (min_a_b - 1) / num) {
            break;
        }
        num *= 2;
        answer++;
    }
    return answer;
}

int main() {
    int n = 8;
    int a = 4;
    int b = 7;
    cout << solution(n, a, b) << "\n";
    return 0;
}

