//���� 14676 ����� ����?
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
		degree[y]++; // ���� ��� ���� 
	}

	int isLier = false;
	for (int i = 0; i < k; i++) {
		int oper, a;
		cin >> oper >> a;

		if (isLier) {
			continue;
		}

		if (oper == 1) {
			// ���� ��尡 ���ų�, �� �������� ��
			if (degree[a] == 0) {
				build[a]++;
				// ó�� �Ǽ��Ǿ��� ��
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
			// �Ǽ����� ���� �ǹ��� �ı��� ��
			if (build[a] == 0) {
				isLier = true;
				continue;
			}
			else {
				build[a]--;
				// �ǹ��� ��� �ı��Ǿ��� ��
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