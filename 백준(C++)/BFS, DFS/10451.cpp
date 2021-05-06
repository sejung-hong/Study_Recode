//10451 순열사이클
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001] = { 0, };
bool visited[1001] = { false, };
int cycle = 0;

void DFS(int node) {
	visited[node] = true;
	int next = arr[node];
	if (visited[next] != true) {
		DFS(next);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;

	int num;
	for (int i = 0; i < T; i++) {
		cin >> N;

		fill(visited, visited + 1001, 0);
		fill(arr, arr + 1001, 0);
		cycle = 0;

		for (int j = 1; j <= N; j++) {
			cin >> arr[j];
		}

		for (int k = 1; k <= N; k++) {
			if (visited[k] == false) {
				DFS(k);
				cycle++;
			}
		}
		cout << cycle << "\n";
	}
	return 0;
}