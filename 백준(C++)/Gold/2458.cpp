//백준 2458 키 순서
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int height[501][501] = { 0, };

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		height[a][b] = 1;
	}

	//플로이드 와샬
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (height[i][k] && height[k][j]) {
					height[i][j] = 1;
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		int count = 0;
		for (int j = 1; j <= N; j++) {
			if (height[i][j] == 1 || height[j][i] == 1) //내가 이긴사람이 있거나 나를 이긴사람이 있거나
				count++;
		}
		if (count == N - 1)
			answer++;
	}

	cout << answer << "\n";


	return 0;
}

//걸린시간 1시간