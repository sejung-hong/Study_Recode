//백준 1956 운동
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//연산속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	int graph[401][401] = { 0, };
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c; //a->b = c
	}

	//플로이드 와샬(사이클찾기)
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] != 0)
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); //최소거리
					else
						graph[i][j] = graph[i][k] + graph[k][j];
				}
			}

		}
	}

	int answer = 10000000000; //max
	int check = 0;
	for (int i = 1; i <= V; i++) {
		if (graph[i][i] != 0) {
			answer = min(answer, graph[i][i]); //최소 도로의 길이
			check = 1;
		}
	}

	if (check == 0)
		cout << "-1\n"; //사이클이 없는 경우
	else
		cout << answer << "\n";


	return 0;
}

//걸린 시간 : 30분