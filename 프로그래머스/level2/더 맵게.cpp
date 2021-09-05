//���α׷��ӽ� �� �ʰ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //�켱���� ť �������� ����
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K) {
        if (pq.size() < 2) {
            answer = -1;
            break;
        }
        int a = pq.top(); //���� ���� ���� ����
        pq.pop();
        int b = pq.top(); //�� ��°�� ���� ���� ����
        pq.pop();
        pq.push(a + (b * 2)); //���� ����
        answer++; //���� Ƚ��
    }
    return answer;
}

int main() {
    vector<int> scoville = { 1,2,3,9,10,12 };
    int K = 7;
    cout << solution(scoville, K) << "\n";
    return 0;
}