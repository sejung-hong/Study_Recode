//���α׷��ӽ� ��ũ ��Ʈ�ѷ�
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0; 

    sort(jobs.begin(), jobs.end()); // �������� ����
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //�������� 
    int time = 0; 
    int idx = 0;

    while (idx < jobs.size() || !pq.empty()) {
        if (idx < jobs.size() && time >= jobs[idx][0]) {
            pq.push({ jobs[idx][1], jobs[idx][0] }); //push
            idx++; //���� �۾�
            continue;
        }
        if (!pq.empty()) {
            time += pq.top().first;
            answer += time - pq.top().second; //��û���� �������
            pq.pop();
        }
        else {
            time = jobs[idx][0];
        }
    }

    answer = answer / jobs.size();
    return answer;
        
}


int main() {
    vector<vector<int>> jobs = { {0,3}, {1,9}, {2,6} };
    cout << solution(jobs) << "\n";
    return 0;
}