//11021
#include <iostream>
using namespace std;

int main() {
	int T = 0, a = 0, b = 0;

	cin >> T; //test case

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << "Case #"<< i+1 << ": " << a + b << endl;
	}
	return 0;
}
//Case #으로 출력