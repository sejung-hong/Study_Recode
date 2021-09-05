//프로그래머스 더 맵게
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //우선순위 큐 오름차순 정렬
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K) {
        if (pq.size() < 2) {
            answer = -1;
            break;
        }
        int a = pq.top(); //가장 맵지 않은 음식
        pq.pop();
        int b = pq.top(); //두 번째로 맵지 않은 음식
        pq.pop();
        pq.push(a + (b * 2)); //섞은 음식
        answer++; //섞은 횟수
    }
    return answer;
}

int main() {
    vector<int> scoville = { 1,2,3,9,10,12 };
    int K = 7;
    cout << solution(scoville, K) << "\n";
    return 0;
}