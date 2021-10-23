//백준 1922 네트워크 연결
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//간선의 길이가 짧은 순으로 정렬
bool cmp(vector<int>& a, vector<int>& b) {
	return a[2] < b[2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int N, M;
	cin >> N;
	cin >> M;
	vector<vector<int>> line;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> v;
		v.push_back(a); v.push_back(b); v.push_back(c);
		line.push_back(v);
	}

	sort(line.begin(), line.end(), cmp); //정렬

	queue<vector<int>> q;
	int cost = 0;
	q.push(line[0]);
	line.erase(line.begin());

	int visited[1001] = { 0, };
	while (!q.empty()) {
		//노드 방문
		visited[q.front()[0]] = 1;
		visited[q.front()[1]] = 1;
		cost += q.front()[2];

		for (int i = 0; i < line.size(); i++) {
			//둘 중 하나만 방문되었을 때(XOR)
			if (visited[line[i][0]] ^ visited[line[i][1]]) {
				q.push(line[i]);
				line.erase(line.begin() + i);
				break;
			}
		}
		q.pop(); 

	}

	cout << cost << "\n";


	return 0;
}
//걸린 시간 : 30분