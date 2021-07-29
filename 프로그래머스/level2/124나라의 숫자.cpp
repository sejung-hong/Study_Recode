//프로그래머스 124나라의 숫자
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    while (n) {
        n--;
        if (n % 3 == 0)
            answer = "1" + answer;

        else if (n % 3 == 1) 
            answer = "2" + answer;
        
        else 
            answer = "4" + answer;
        
        n /= 3;
    }

    return answer;
}

int main() {
    int n = 9;
    cout << solution(n) << "\n";
    return 0;
}
