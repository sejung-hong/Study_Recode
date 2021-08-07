//프로그래머스 점프와 순간 이동
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            ans++; //건전지 사용량 +1
            n--; //수 -1
        }
        n /= 2;
    }

    return ans;
}

int main() {
    int n = 5000;
    cout << solution(n) << "\n";
    return 0;
}