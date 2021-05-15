//1373 2진수 8진수
#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string binary;
	cin >> binary;

	if (binary.size() % 3 == 1)
		cout << binary[0] - 48;
	else if (binary.size() % 3 == 2)
		cout << (binary[0] - 48) * 2 + (binary[1] - 48);
	
	for (int i = binary.size() % 3; i < binary.size(); i += 3) {
		cout << (binary[i] - 48) * 4 + (binary[i + 1] - 48) * 2 + (binary[i + 2] - 48);
	}
	cout << "\n";

	return 0;
}