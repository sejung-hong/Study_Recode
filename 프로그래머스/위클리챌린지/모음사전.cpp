//프로그래머스 위클리 챌린지 모음 사전
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;

    answer += word.size();
    for (int i = 0; i < word.size(); i++) {
        int sum = 0;
        int five = 1;
        int n = 0;
        if (word[i] == 'E') n = 1;
        else if (word[i] == 'I') n = 2;
        else if (word[i] == 'O') n = 3;
        else if (word[i] == 'U') n = 4;

        for (int j = 0; j < 5 - i; j++) {
            sum += five;
            five *= 5;
        }
        answer += (sum * n);
    }

    return answer;
}

int main() {
    string word = "AAE";
    cout << solution(word) << "\n";
    return 0;
}