//1978 소수 찾기
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int num = 0;
	int a;
	int check;

	for (int i = 0; i < N; i++) {
		check = 0;
		cin >> a;
		for (int j = 2; j < a; j++) {
			if (a % j == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0 && a != 1) {
			num++;
		}
	}
	
	cout << num << endl;

	return 0;
}