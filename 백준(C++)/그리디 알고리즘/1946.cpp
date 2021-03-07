//1946 신입사원
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, N;

	cin >> T;
	
	for (int j = 0; j < T; j++) {
		cin >> N;

		vector <pair<int, int>> grade;
		pair<int, int> p;

		for (int i = 0; i < N; i++) {
			cin >> p.first >> p.second;
			grade.push_back(p);
		}

		sort(grade.begin(), grade.end()); //오름차순으로 정렬

		vector<pair<int, int>> compare;

		int a, b = 0;
		int pick = 0;

		a = grade[0].first;
		b = grade[0].second;
		pick++;

		for (int i = 1; i < N; i++) {
			if (b > grade[i].second) {
				pick++;
				b = grade[i].second;
			}
		}

		cout << pick << endl;

	}

	return 0;
}