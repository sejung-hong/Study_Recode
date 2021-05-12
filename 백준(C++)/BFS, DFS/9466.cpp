//9466 ер га╥на╖ф╝
#include <iostream>
#include <cstring>
using namespace std;
int visited[100001] = { 0, };
int student[100001] = { 0, };
bool check[100001] = { false, };

void DFS(int node) {
	visited[node]++;

	int next = student[node];
	if (check[next] == true) {
		check[node] = true;
		return;
	}

	if (visited[node] > 2) {
		return;
	}

	DFS(next);
	check[node] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	
	int n;
	int s;

	for (int i = 0; i < T; i++) {
		memset(student, 0, sizeof(student));
		memset(visited, 0, sizeof(visited));
		memset(check, 0, sizeof(check));

		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> s;
			student[j] = s;
		}
		for (int j = 1; j <= n; j++) {
			if (visited[j] == 0)
				DFS(j);
		}

		int num = 0;
		for (int j = 1; j <= n; j++) {
			if (visited[j] == 1) {
				num++;
			}
		}
		cout << num << "\n";
	}

	return 0;
}