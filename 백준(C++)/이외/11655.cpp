//11655 ROT13
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if ((int)s[i] - 110 < 0)
				cout << char((int)s[i] + 13);
			else {
				cout << char((int)s[i] - 13);
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if ((int)s[i] - 78 < 0)
				cout << char((int)s[i] + 13);
			else {
				cout << char((int)s[i] - 13);
			}
		}
		else
			cout << s[i];
	}

	return 0;
}