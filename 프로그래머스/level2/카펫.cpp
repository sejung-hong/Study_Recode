//프로그래머스 카펫
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 3; i <= (brown + yellow) / 2; i++) {
        if ((brown + yellow) % i == 0) {
            int j = (brown + yellow) / i;
            if ((i - 2) * (j - 2) == yellow) {
                answer.push_back(j);
                answer.push_back(i);
                break;
            }
        }
    }

    return answer;
}

int main() {
    int brown = 8;
    int yellow = 1;
    solution(brown, yellow);
    return 0;
}