//3460 이진수
#include <iostream>
using namespace std;

int main() {
	int T, n;
	cin >> T;
	int array[20]; //이진수 저장

	for (int i = 0; i < T; i++) {
		cin >> n;
		int k = 0;
		while (1) {
			if (n % 2 == 0) {
				array[k] = 0; //나머지 0
			}
			else
				array[k] = 1; //나머지 1
			n /= 2;
			k++;
			if (n == 1 || n == 0) {
				array[k] = n;
				break;
			}

		}
		for (int j = 0; j < k + 1; j++) {
			if (array[j] == 1) {
				cout << j << " ";
			}
		}
		cout << endl;
	}

	return 0;
	//13 = 1101 : 0 2 3 출력
}