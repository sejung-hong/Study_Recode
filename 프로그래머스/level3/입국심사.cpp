//���α׷��ӽ� �Ա��ɻ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long left = 1; //�ּ�
    long long right = (long long)times[times.size() - 1] * n; //�ִ�
    long long mid;

    while (left <= right) {
        mid = (left + right) / 2;

        long long count = 0; //mid �ð����� �ɻ� ó���� �� �ִ� ��� ��

        for (int i = 0; i < times.size(); i++) {
            count += mid / times[i];
        }
        
        if (count < n) { //�ɻ� �� �� �ִ� ��� ���� ���� ��
            left = mid + 1;
        }
        else if(count >= n) { //�ɻ� �� �� �ִ� ��� ���� ���� ��
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