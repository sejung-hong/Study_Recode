//10809 ¾ËÆÄºª Ã£±â
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int location[26] = {};
	fill(location, location + 26, -1);
	for (int i = 0; i < s.size(); i++) {
		if (location[(int)s[i] - 97] == -1) {
			location[(int)s[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << location[i] << " ";
	}
	return 0;
}