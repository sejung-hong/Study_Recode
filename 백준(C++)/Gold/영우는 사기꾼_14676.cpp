//백준 14676 영우는 사기꾼?
#include <iostream>
#include <vector>

using namespace std;

int degree[100001] = { 0, };
int build[100001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		degree[y]++; // 이전 노드 개수 
	}

	int isLier = false;
	for (int i = 0; i < k; i++) {
		int oper, a;
		cin >> oper >> a;

		if (isLier) {
			continue;
		}

		if (oper == 1) {
			// 이전 노드가 없거나, 다 지어졌을 때
			if (degree[a] == 0) {
				build[a]++;
				// 처음 건설되었을 때
				if (build[a] == 1) {
					for (int j = 0; j < graph[a].size(); j++) {
						degree[graph[a][j]]--;
					}
				}
			}
			else {
				isLier = true;
				continue;
			}

		}
		else if (oper == 2) {
			// 건설한적 없는 건물이 파괴될 때
			if (build[a] == 0) {
				isLier = true;
				continue;
			}
			else {
				build[a]--;
				// 건물이 모두 파괴되었을 때
				if (build[a] == 0) {
					for (int j = 0; j < graph[a].size(); j++) {
						degree[graph[a][j]]++;
					}
				}
			}
		}
	}

	if (isLier) {
		cout << "Lier!" << "\n";
	}
	else if (!isLier) {
		cout << "King-God-Emperor" << "\n";
	}


	return 0;
}