// 10814 나이순 정렬
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector <pair<int, string>> vec;

	int age;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		vec.push_back(make_pair(age, name));
	}

	stable_sort(vec.begin(), vec.end(), compare); //안정정렬

	for (int i = 0; i < N; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}


	return 0;
}