//���α׷��ӽ� ������ ���� �̵�
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            ans++; //������ ��뷮 +1
            n--; //�� -1
        }
        n /= 2;
    }

    return ans;
}

int main() {
    int n = 5000;
    cout << solution(n) << "\n";
    return 0;
}