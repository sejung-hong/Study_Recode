//2750 �� �����ϱ� �˰��� ��� ���
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector <int> v;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i] << "\n";
	}


	return 0;
}