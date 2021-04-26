//11724 연결 요소의 개수
#include<iostream>
#include <vector>
using namespace std;
bool visited[1001] = { false, };
vector <int> vec[1001];
int N, M;
int num = 0;

void DFS(int node) {
	visited[node] = true;
	for (int i = 0; i < vec[node].size(); i++) {
		int next = vec[node][i];
		if (!visited[next])
			DFS(next);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;


	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			num++;
			DFS(i);
		}
	}

	cout << num << "\n";


	return 0;
}