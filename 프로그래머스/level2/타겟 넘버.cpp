//프로그래머스 타겟 넘버
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> q;
    q.push(0);
    for (int i = 0; i < numbers.size(); i++) {
        int size = q.size();
        for (int j = 0; j < size; j++) {
            q.push(q.front() - numbers[i]);
            q.push(q.front() + numbers[i]);
            q.pop();
        }
    }

    while (!q.empty()) {
        if (q.front() == target) {
            answer++;
        }
        q.pop();
    }

    return answer;
}

int main() {
    vector <int> numbers = { 1,1,1,1,1 };
    int target = 3;
    cout << solution(numbers, target) << "\n";
    return 0;
}
