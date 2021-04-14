// 11652 카드
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

bool compare(const pair<long long, int>& a, const pair<long long, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map <long long, int> m;

	long long a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		m[a]++;

	}

	vector<pair<long long, int>> vec(m.begin(), m.end()); //map을 vector로 이동
	sort(vec.begin(), vec.end(), compare); //정렬

	cout << vec[0].first <<"\n";

	return 0;
}