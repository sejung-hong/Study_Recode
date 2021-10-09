//2675 문자열 반복
#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		string s;
		cin >> n >> s;
		for (int j = 0; j < s.size(); j++) {
			for (int k = 0; k < n; k++) {
				cout << s[j];
			}
		}
		cout << "\n";
	}
	return 0;
}