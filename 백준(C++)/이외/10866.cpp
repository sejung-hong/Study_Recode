//10866 µ¦
#include <iostream>
#include <deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N; 
	cin >> N;

	int n;
	string command;
	deque <int> dq;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push_front") {
			cin >> n;
			dq.push_front(n);
		}
		else if (command == "push_back") {
			cin >> n;
			dq.push_back(n);
		}
		else if (command == "pop_front") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (command == "size") {
			cout << dq.size() << "\n";
		}
		else if (command == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (command == "front") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (command == "back") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}
	return 0;
}