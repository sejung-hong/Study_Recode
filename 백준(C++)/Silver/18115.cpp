//น้มุ 18115
#include <iostream>
#include <deque>

using namespace std;

int arr[1000001];

int main() {
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[i] = num;
	}

	deque<int> dq;

	for (int i= N - 1; i >= 0; i--) {
		if (arr[i] == 1) {
			dq.push_front(N - i);
		}
		else if (arr[i] == 2) {
			dq.insert(dq.begin() + 1, N - i);
		}
		else if (arr[i] == 3) {
			dq.push_back(N - i);
		}
	}

	while (!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}
	
	return 0;
}