//백준 11404 플로이드
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000

int weight[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				weight[i][j] = 0;
			}
			else {
				weight[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		weight[a][b] = min(weight[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				weight[i][j] = min(weight[i][j], weight[i][k] + weight[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (weight[i][j] == INF) {
				cout << "0" << " ";
			}
			else {
				cout << weight[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}