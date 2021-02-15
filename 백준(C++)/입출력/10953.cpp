//10953
#include <iostream>
using namespace std;

int main() {
	int T = 0, a = 0, b = 0;
	char comma;

	cin >> T; //test case

	for (int i = 0; i < T; i++) {
		cin >> a >> comma >>b;
		cout << a + b << endl;
	}
	return 0;
}
//,로 구분되는 경우