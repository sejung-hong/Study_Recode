//프로그래머스 최대공약수와최소공배수
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int n, int m) {
    if (m == 0) {
        return n;
    }
    return GCD(m, n % m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd = GCD(n, m);
    answer.push_back(gcd);
    answer.push_back((n * m) / gcd);
    return answer;
}

int main() {
    int n = 3;
    int m = 12;

    cout << solution(n, m)[0] << solution(n, m)[1] << "\n";

    return 0;
}