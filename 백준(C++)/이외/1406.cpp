//1406 에디터
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	list<char> l(s.begin(), s.end());
	auto cursor = l.end();

	int M;
	cin >> M;

	char command;
	for (int i = 0; i < M; i++) {
		cin >> command;

		if (command == 'L') {
			if (cursor != l.begin()) {
				cursor--;
			}
		}
		else if (command == 'D') {
			if (cursor != l.end()) {
				cursor++;
			}
		}
		else if (command == 'B') {
			if (cursor != l.begin()){
				cursor = l.erase(--cursor);
			}
		}
		else if (command == 'P') {
			char add;
			cin >> add;
			l.insert(cursor, add);
		}
	}

	for (auto it = l.begin(); it != l.end(); it++) {
		cout << *it;
	}//반복자

	cout << "\n";

	return 0;
}