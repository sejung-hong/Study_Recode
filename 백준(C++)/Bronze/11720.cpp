//11720 ������ ��
#include <iostream>
using namespace std;

int main() {
	int n;
	string num;

	cin >> n;
	cin >> num;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i] - 48; //�ƽ�Ű�ڵ�
	}
	cout << sum << "\n";
	
	return 0;
}