//10808 ¾ËÆÄºª °³¼ö
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int alphabet[26] = { 0, };
	for (int i = 0; i < s.size(); i++) {
		alphabet[(int)s[i]-97]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}

	return 0;
}