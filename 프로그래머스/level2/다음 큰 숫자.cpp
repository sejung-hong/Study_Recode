//프로그래머스 다음 큰 숫자
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int one_num(int n) {
    int num = 0;
    while (n > 0) {
        if (n % 2 == 1)
            num++;
        n /= 2;
    }
    return num;
}

int solution(int n) {
    int answer = 0;
    int n_one = one_num(n);

    for (int i = n + 1; i <= 1000000; i++) {
        if (n_one == one_num(i)) {
            answer = i;
            break;
        }
    }
    return answer;
}

int main() {
    int n = 78;
    cout << solution(n) << "\n";
    return 0;
}