//���α׷��ӽ� x��ŭ ������ �ִ� n���� ����
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    for (int i = 1; i <= n; i++) {
        answer.push_back(x * i);
    }

    return answer;
}

int main() {
    int x = -4;
    int n = 2;

    solution(x, n);

    return 0;
}