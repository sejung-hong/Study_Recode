//1292 쉽게 푸는 문제
#include<iostream>
using namespace std;

int main() {
	int A, B;
	int add = 1;
	int num = add; //더해져야할 개수
	int sum = 0;

	cin >> A >> B;

	for (int i = 1; i <= B; i++) {

		if (num == 0) {
			add++;
			num = add;
		}

		if (i >= A)
			sum += add;

		num--;
	}

	cout << sum << endl;
	return 0;
}