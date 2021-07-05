//프로그래머스 나누어떨어지는숫자배열
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }

    if (answer.empty()) {
        answer.push_back(-1);
    }
    else {
        sort(answer.begin(), answer.end());

    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return answer;
}

int main() {
    vector<int> arr = { 5,9,7,10 };
    int divisor = 5;

    solution(arr, divisor);

    return 0;
}