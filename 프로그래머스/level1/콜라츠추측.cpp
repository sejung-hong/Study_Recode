//프로그래머스 콜라츠 추측
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    for (int i = 0; i < 500; i++) {
        if (n == 1) {
            break;
        }
        
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n += 1;
        }
        answer++;
    }

    if (answer >= 500) {
        answer = - 1;
    }
    
    return answer;
}

int main() {
    int n = 626331;
    cout << solution(n) << "\n";
    return 0;
}