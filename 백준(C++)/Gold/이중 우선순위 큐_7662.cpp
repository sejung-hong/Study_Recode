//백준 7662 이중 우선순위 큐
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int k;
		cin >> k;

		multiset<int> m;
		while (k--) {
			char c;
			int n;
			cin >> c >> n;

			if (c == 'I') {
				m.insert(n);
			}
			else if (c == 'D') {
				if (m.empty()) {
					continue;
				}
				if(n == 1){
					m.erase(--m.end());
				}
				else if (n == -1) {
					m.erase(m.begin());
				}
			}
		}
		
		if (m.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << *(--m.end()) << " " << *(m.begin()) << "\n";
		}
	}

	return 0;
}