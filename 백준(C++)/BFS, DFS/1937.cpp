//1937 욕심쟁이 판다
#include <iostream>
#include <cstring>
using namespace std;
int n;
int denamu[501][501]; //대나무 숲
int visited[501][501]; //이동 거리
int move_panda = 0;
int max_move = 0;
int nx[4] = { 1, 0, -1, 0 }, ny[4] = { 0, 1, 0, -1 };

int DFS(int x, int y) {
	if (visited[x][y]) //방문했던 위치
		return visited[x][y];

	visited[x][y] = 1;
	move_panda = 0;

	for (int i = 0; i < 4; i++) {
		int next_x = x + nx[i];
		int next_y = y + ny[i]; 
		//이동할 위치
		
		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
			continue;
		//벗어난 위치

		if (denamu[x][y] < denamu[next_x][next_y]) {
			move_panda = DFS(next_x, next_y) + 1;
			if (visited[x][y] < move_panda)
				visited[x][y] = move_panda;
		}
		//이전 위치보다 대나무 많은 곳
	}
	
	return visited[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> denamu[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int result = DFS(i, j);
			if (max_move < result) {
				max_move = result;
			}
		}
	}

	cout << max_move << "\n";

	return 0;
}