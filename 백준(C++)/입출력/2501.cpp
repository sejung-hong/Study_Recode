//2501 ��� ���ϱ�
#include <iostream>
using namespace std;

int main() {
	int N, K = 0; //N,K�� �ڿ���
	cin >> N >> K;
	//0 < N <= 10000, 0 < K <=N 

	int divisor[10000] = { 0, }; //����� �����ϴ� �迭 0���� �ʱ�ȭ

	int num = 0; //����� ����
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			divisor[num] = i; //��� ����
			num++;
		}
	}

	if (num < K) { //K��° ����� �������� ���� ���
		cout << "0" << endl;
	}
	else
		cout << divisor[K-1] << endl; //�迭�� 0���� ����Ǳ� ������ K-1��° �迭 ���

	return 0;
}