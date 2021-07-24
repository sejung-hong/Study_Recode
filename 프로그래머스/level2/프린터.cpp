//프로그래머스 프린터
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> p_q;

    for (int i = 0; i < priorities.size(); i++) {
        q.emplace(i, priorities[i]);
        p_q.push(priorities[i]);
    }

    while (!q.empty()) {
        if (p_q.top() == q.front().second) {
            p_q.pop();
            answer++;
            if (q.front().first == location) {
                break;
            }
        }
        else {
            q.emplace(q.front().first, q.front().second);
        }
        q.pop();
    }
    return answer;
}

int main() {
    vector<int> priorities = { 1,2, 1,3 };
    int location = 0;
    cout << solution(priorities, location) << "\n";
    return 0;
}