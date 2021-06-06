//10874 모든 순열
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> vec(N);
	for (int i = 1; i <= N; i++) {
		vec[i - 1] = i;
	}

	do {
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			cout << *it << " ";
		}
		cout << "\n";
	} while (next_permutation(vec.begin(), vec.end()));

	
	return 0;
}