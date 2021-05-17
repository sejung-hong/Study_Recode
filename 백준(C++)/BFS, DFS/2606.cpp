//2606 바이러스
#include <iostream>
#include <vector>
using namespace std;
vector <int> v[101];
bool visited[101] = { false, };
int virus = 0;

void DFS(int node) {
	visited[node] = true;
	virus++;

	for (int i = 0; i < v[node].size(); i++) {
		if (visited[v[node][i]] == false)
			DFS(v[node][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_computer;
	cin >> num_computer;

	int num_pair;
	cin >> num_pair;

	for (int i = 0; i < num_pair; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);

	cout << virus - 1 << "\n";

	return 0;
}