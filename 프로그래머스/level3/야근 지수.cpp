//���α׷��ӽ� �߱� ����
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq; //�켱���� ť
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }

    for (int i = 0; i < n; i++) {
        if (pq.empty())
            break;
        int num = pq.top();
        pq.pop();
        //0�� �ƴҶ� push
        if (num - 1 != 0)
            pq.push(num - 1);
    }
    
    while (!pq.empty()) {
        answer += pow(pq.top(), 2); //����
        pq.pop();
    }

    return answer;
}

int main() {
    int n = 4;
    vector<int> works = { 4,3,3 };
    cout << solution(n, works) << "\n";
    return 0;
}