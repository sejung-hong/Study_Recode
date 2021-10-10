//10828 Ω∫≈√
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack <int> s;
	string command;

	int n;
	for (int i = 0; i < N; i++) {
		cin >> command;

		if (command == "push") {
			cin >> n;
			s.push(n);
		}
		else if (command == "pop") {
			if (s.empty()) {
				cout << "-1\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (command == "size") {
			cout << s.size() << "\n";
		}
		else if (command == "empty") {
			if (s.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}

		}
		else if (command == "top") {
			if (s.empty()) {
				cout << "-1\n";
			}
			else {
				cout << s.top() << "\n";
			}
		}
		else
			return 0;
	}
	

	return 0;
}