//백준 2110 공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;
	vector <int> house;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		house.push_back(num);
	}

	sort(house.begin(), house.end());

	int dis = 0;
	int left = 1; //공유기 사이 거리 최소
	int right = house[N - 1] - house[0]; // 공유기 사이 거리 최대
	while (left <= right) {
		int count = 1;
		int mid = (left + right) / 2;
		int cur = house[0];
		for (int i = 1; i < N; i++) {
			if (house[i] - cur >= mid) {
				cur = house[i];
				count++;
			}
		}
		if (count >= C) {
			dis = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << dis << "\n";

	
	return 0;
}