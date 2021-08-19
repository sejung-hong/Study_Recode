//프로그래머스 멀리뛰기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;

    long long visited[2001];
    visited[1] = 1;
    visited[2] = 2;
    for (int i = 3; i <= n; i++) {
        visited[i] = (visited[i - 2] + visited[i - 1]) % 1234567;
    }

    return visited[n];
}

int main() {
    int n = 4;
    cout << solution(n) << "\n";
    return 0;
}
