//프로그래머스 입국심사
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long left = 1; //최소
    long long right = (long long)times[times.size() - 1] * n; //최대
    long long mid;

    while (left <= right) {
        mid = (left + right) / 2;

        long long count = 0; //mid 시간동안 심사 처리할 수 있는 사람 수

        for (int i = 0; i < times.size(); i++) {
            count += mid / times[i];
        }
        
        if (count < n) { //심사 할 수 있는 사람 수가 적을 때
            left = mid + 1;
        }
        else if(count >= n) { //심사 할 수 있는 사람 수가 많을 때
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}

int main() {
    int n = 6;
    vector<int> times = { 7,10 };
    cout << solution(n, times) << "\n";
    return 0;
}