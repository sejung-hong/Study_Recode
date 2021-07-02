//프로그래머스 햐사드 수
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int a = x;
    int sum = 0;
    while (a > 0) {
        sum += (a % 10);
        a /= 10;
    }
    
    if (x % sum != 0) {
        answer = false;
    }

    return answer;
}

int main() {
    int x = 10;

    cout << solution(x) << "\n";

    return 0;
}