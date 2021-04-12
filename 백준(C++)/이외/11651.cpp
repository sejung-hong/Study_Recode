//11650 ��ǥ �����ϱ�
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector <pair<int, int>> vec;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		vec.push_back(make_pair(y, x));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		cout << vec[i].second << " " << vec[i].first << "\n";
	}

	return 0;
}
