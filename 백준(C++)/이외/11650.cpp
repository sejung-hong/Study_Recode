//11650 좌표 정렬하기
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
		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}

	return 0;
}



