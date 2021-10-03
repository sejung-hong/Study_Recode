//프로그래머스 2xn 타일링
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[600001];

int DP(int num) {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= num; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    return dp[num];
}

int solution(int n) {
    int answer = 0;

    answer = DP(n);

    return answer;
}

int main() {
    int n = 4;
    cout << solution(n) << "\n";
    return 0;
}