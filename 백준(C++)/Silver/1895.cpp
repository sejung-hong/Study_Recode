//백준 1895 필터
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int R, C; // 행,열
	cin >> R >> C;
	int board[41][41];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int num;
			cin >> num;
			board[i][j] = num;
		}
	}

	int T;
	cin >> T;

	int ans = 0;
	for (int i = 0; i < R - 2; i++) {
		for (int j = 0; j < C - 2; j++) {
			vector<int> v;
			for (int ii = 0; ii < 2; ii++) {
				for (int jj = 0; jj < 2; jj++) {
					v.push_back(board[i + ii][j + jj]);
				}
			} //필터 3x3만큼 push

			sort(v.begin(), v.end()); //정렬

			if (v[4] >= T) // 중앙값 T와 비교
				ans++;
		}
	}
	
	cout << ans << "\n";


	return 0;
}

//걸린시간 : 15분
