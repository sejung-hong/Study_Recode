// 3:땅따먹기
#include <iostream>
using namespace std;
int ground[201][201] = { 0, };
bool visited[201][201] = { false, };
int x[4] = { -1, 0, 1, 0 }, y[4] = { 0,1,0,-1 };
int P[10] = { 0, };
int r, c; //맵의 크기

void DFS(int a, int b, int person) {
	visited[a][b] = true;
	for (int i = 0; i < 4; i++) {
		int nx = a + x[i];
		int ny = b + y[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
			continue;
		}
		if (visited[nx][ny] == false && ground[nx][ny] == person) {
			DFS(nx, ny, person);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; //N:플레이어 수, M:명령어 수

	cin >> r >> c >> N >> M;

	int n;
	int r1, c1, r2, c2;
	int p;
	for (int i = 0; i < M; i++) {
		cin >> n;
		if (n == 1) {
			cin >> r1 >> c1 >> r2 >> c2;
			ground[r2][c2] = ground[r1][c1];
		}
		else if (n == 2) {
			cin >> r1 >> c1 >> p;
			ground[r1][c1] = p;
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] == false) {
				int person = ground[i][j];
				DFS(i, j, person);
				P[person]++;
			}
;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << P[i] << " ";
	}
	cout << "\n";

	return 0;
}