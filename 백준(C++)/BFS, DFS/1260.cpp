//1260 DFS와 BFS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int>* graph = new vector<int>[1001];
bool visited_DFS[1001];
bool visited_BFS[1001];

//DFS 깊이 우선탐색
void DFS(int v) {
	visited_DFS[v] = true; //방문:ture
	cout << v << " ";

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited_DFS[next])
			DFS(next);
	}
}

//BFS 넓이 우선탐색
void BFS(int v) {
	visited_BFS[v] = true; //방문:ture
	queue<int> q;
	q.push(v);
	
	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i];
			if (!visited_BFS[next]) {
				visited_BFS[next] = true;
				q.push(next);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;


	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}//그래프 생성
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	} // 정렬

	DFS(V);
	cout << "\n";
	BFS(V);
	cout << "\n";

	return 0;
}