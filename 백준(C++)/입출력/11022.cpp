//11021
#include <iostream>
using namespace std;

int main() {
	int T = 0, a = 0, b = 0;

	cin >> T; //test case

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << endl;
	}
	return 0;
}
//Case #num : a + b = a+b ·Î Ãâ·Â