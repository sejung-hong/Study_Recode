//2875 ��ȸ or ����
#include <iostream>
using namespace std;

int main() {
	int N, M, K;
	//N: ���л� ��
	//M: ���л� �� 
	//K: ���Ͻ��� �����ؾ��ϴ� �ο�
	cin >> N >> M >> K;

	int team = 0;

	if (N / 2 <= M){
		team = N / 2;
	}
	else if (N / 2 > M) {
		team = M;
	}
	//���Ͻ��� ������� �ʰ� ���� �� �ִ� ��

	K = K - (N - team * 2) - (M - team);

	if (K > 0) {
		if (K % 3 == 0) {
			team -= K / 3;
		}
		else {
			team = team - (K / 3) - 1;
		}
	}

	cout << team << endl;

	return 0;
}
//�θ��� ���л��� 1���� ���л�