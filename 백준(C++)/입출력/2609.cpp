//2609 �ִ������� �ּҰ����
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int small = 0;
	int min, max;

	if (a < b)
		small = a;
	else
		small = b;

	for (int i = small; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			max = i;
			cout << max << endl;
			break;
		}
	}//�ִ�����

	min = max * (a / max) * (b / max);
	cout << min << endl;
	//�ּҰ����

	return 0;
}