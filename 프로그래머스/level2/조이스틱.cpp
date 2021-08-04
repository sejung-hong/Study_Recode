//프로그래머스 조이스틱
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    int turn = name.size() - 1;
    int n = name.size();
    for (int i = 0; i < name.size(); i++) {
        if (name[i] - 'A' <= 13) {
            answer += (name[i] - 'A');
        }
        else {
            answer += 26 - (name[i] - 'A');
        }
        
        int next = i + 1; //다음 문자
        while (next < name.size() && name[next] == 'A')
            next++;
        turn = min(turn, i + n - next + min(i, n - next));

    }

    answer += turn;
    return answer;
}

int main() {
    string name = "ABBAAAB";
    cout << solution(name) << "\n";
    return 0;
}
