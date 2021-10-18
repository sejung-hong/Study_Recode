//백준 2670 연속부분최대곱
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<double> v;
	for (int i = 0; i < N; i++) {
		double num;
		cin >> num;
		v.push_back(num);
	}
	
	double dp[10001] = { 0.0, };
	double M = 0.0;
	dp[0] = v[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(v[i], v[i] * dp[i - 1]);
		M = max(M, dp[i]);
	}

	printf("%.3f", M); //소수점 세자리
	//cout << lround(M * 1000) / 1000.0 << "\n"; //반올림

	return 0;
}