//���α׷��ӽ� ������ ǥ��
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += j; //�� ���ϱ�
            if (sum == n) {
                answer++; //����
                break;
            }
            else if (sum > n)
                break;
        }
    }
    return answer;
}

int main() {
    int n = 15;
    cout << solution(n) << "\n";
    return 0;
}