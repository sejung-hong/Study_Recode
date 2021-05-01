//11656 접미사 배열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	cin >> S;

	vector <string> suffix;

	for (int i = 0; i < S.size(); i++) {
		string sub;
		for (int j = i; j < S.size(); j++) {

			sub += S[j];
		}
		suffix.push_back(sub);
	}

	sort(suffix.begin(), suffix.end());

	for (int i = 0; i < suffix.size(); i++) {
		cout << suffix[i] << "\n";
	}

	return 0;
}