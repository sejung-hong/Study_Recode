//4963 섬의 개수
#include <iostream>
#include <cstring> //memset
using namespace std;
int w, h;
bool map[51][51] = { false, };
bool visited[51][51] = { false, };
int nx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }, ny[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//인접한 모든 배열 위치 방문 가능

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int next_x = x + nx[i];
		int next_y = y + ny[i];
		if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w) {
			continue;
		} 
		if (map[next_x][next_y] == true && visited[next_x][next_y] == false) {
			DFS(next_x, next_y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		int island;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island;
				map[i][j] = island; // x축은 높이 h, y축은 넓이 w
			}
		}//지도 배열 생성

		int num_island = 0; //섬의 개수
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visited[i][j] == false) {
					num_island++;
					DFS(i, j);
				}
			}
		}//DFS

		cout << num_island << "\n";

	}
	
	return 0;
}