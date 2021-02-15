//10952
#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0;

	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		cout << a + b << endl;
	}
	return 0;
}
//입력의 마지막에 0 두개가 들어오는 경우