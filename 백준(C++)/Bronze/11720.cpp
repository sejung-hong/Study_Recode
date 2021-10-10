//11720 숫자의 합
#include <iostream>
using namespace std;

int main() {
	int n;
	string num;

	cin >> n;
	cin >> num;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i] - 48; //아스키코드
	}
	cout << sum << "\n";
	
	return 0;
}