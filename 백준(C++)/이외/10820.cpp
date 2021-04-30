//10820 문자열 분석
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	for (int j = 0; j < 100; j++) {
		getline(cin, s, '\n');
		if (s.size() == 0) {
			break;
		}
		int a = 0, A = 0, num = 0, blank = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				a++;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				A++;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				num++;
			}
			else if (s[i] == ' ') {
				blank++;
			}
		}

		cout << a << " " << A << " " << num << " " << blank << "\n";

	}
	return 0;
}