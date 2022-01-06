//¹éÁØ 1987 ¾ËÆÄºª
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
vector<string> board;
int maxMove = 1;
int nexti[4] = { 1,0,-1,0 }, nextj[4] = { 0,1,0,-1 };
bool alpha[26] = { false, };


bool isLocation(int i, int j) {
	if (i < 0 || j < 0 || i >= R || j >= C) {
		return false;
	}
	return true;
}

void DFS(int i, int j, int move) {
	maxMove = max(maxMove, move);

	for (int k = 0; k < 4; k++) {
		int ni = i + nexti[k];
		int nj = j + nextj[k];
		if (!isLocation(ni, nj)) {
			continue;
		}
		if (alpha[board[ni][nj] - 'A']) {
			continue;
		}
		alpha[board[ni][nj] - 'A'] = true;
		DFS(ni, nj, move + 1);
		alpha[board[ni][nj] - 'A'] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		board.push_back(str);
	}

	alpha[board[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	cout << maxMove << "\n";

	return 0;
}