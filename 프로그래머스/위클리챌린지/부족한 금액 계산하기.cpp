//���α׷��ӽ� ������ �ݾ� ����ϱ�
#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = 0; //���
    for (int i = 1; i <= count; i++) {
        sum += (long long)i * price;
    }
    
    if ((sum - money) < 0)
        return 0;

    return (long long)(sum - money);
}

int main() {
    int price = 3;
    int money = 20;
    int count = 4;
    cout << solution(price, money, count) << endl;
    return 0;
}