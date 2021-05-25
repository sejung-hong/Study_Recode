//1012 유기농 배추
#include <iostream>
#include<cstring> //memset 선언
using namespace std;
int M, N, K;
int bachu[51][51] = { 0, };
bool visited[51][51] = { false, };

int next_x[4] = { 1,0,-1,0 }, next_y[4] = { 0, 1, 0, -1 };

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + next_x[i];
		int ny = y + next_y[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		if (visited[nx][ny] == false && bachu[nx][ny] == 1) {
			DFS(nx, ny);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;

		memset(bachu, 0, sizeof(bachu));
		memset(visited, false, sizeof(visited));
		int earthworm = 0;
		//초기화

		int a, b;
		for (int j = 0; j < K; j++) {
			cin >> a >> b;
			bachu[a][b] = 1;
		}

		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (visited[x][y] == 0 && bachu[x][y] == 1) {
					earthworm++;
					DFS(x, y);
				}
			}
		}

		cout << earthworm << "\n";

	}

	return 0;
}