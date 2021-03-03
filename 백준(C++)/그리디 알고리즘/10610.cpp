//10610 - 30
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	string N;

	cin >> N;

	int sum = 0;
	int check_zero = 0;
	for (int i = 0; i < N.size(); i++) {
		sum += N[i] - '0';
		if (N[i] - '0' == 0) {
			check_zero = 1;
		}
	} // ���ο� ��� string���� size()�� ����

	if (sum % 3 != 0 || check_zero == 0) {
		cout << "-1" << endl;
		return 0;
	}

	sort(N.begin(),N.end(), greater<>()); //sort�Լ� ��� ��������
	
	cout << N << endl;
	
	return 0;
}