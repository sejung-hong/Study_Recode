//프로그래머스 멀쩡한 사각형
#include <iostream>
using namespace std;

int GCD(int w, int h) {
    if (w % h == 0)
        return h;
    return GCD(h, w % h);
}

long long solution(int w, int h) {
    long long answer = 1;
    int gcd = GCD(w, h);

    answer = (long long)w * h - ((long long)(w + h) - gcd);

    return answer;
}

int main() {
    int w = 8;
    int h = 12;
    cout << solution(w, h) << "\n";
    return 0;
}