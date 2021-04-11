//2751 수 정렬하기 2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	cin >> N;

	vector <int> vec;

	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		cout << vec[i] << "\n";
	}

	return 0;
}