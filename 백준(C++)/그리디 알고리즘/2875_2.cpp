//2875 ��ȸ or ����
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M, K;
	//N: ���л� ��
	//M: ���л� �� 
	//K: ���Ͻ��� �����ؾ��ϴ� �ο�
	cin >> N >> M >> K;

	cout << min(min(N / 2, M), (N + M - K)/3) << endl;

	return 0;
}