//归霖 14499 林荤困 奔府扁
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[21][21] = { 0, };
int dice[6] = { 0,0,0,0,0,0 }; //困, 菊, 关, 第, 谅, 快

void moveDiceE() {
	int temp[6] = { dice[4], dice[1], dice[5], dice[3], dice[2], dice[0] };
	copy(temp, temp+6, dice);
}
void moveDiceW() {
	int temp[6] = { dice[5], dice[1], dice[4], dice[3], dice[0], dice[2] };
	copy(temp, temp + 6, dice);
}
void moveDiceN() {
	int temp[6] = { dice[1], dice[2], dice[3], dice[0], dice[4], dice[5] };
	copy(temp, temp + 6, dice);
}
void moveDiceS() {
	int temp[6] = { dice[3], dice[0], dice[1], dice[2], dice[4], dice[5] };
	copy(temp, temp + 6, dice);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	vector <int> move;
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		move.push_back(num);
	}

	for (int i = 0; i < K; i++) {
		if (move[i] == 1) { // 悼率
			int nx = x;
			int ny = y + 1;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			x = nx;
			y = ny;
			moveDiceE();

			if (board[x][y] != 0) {
				dice[2] = board[x][y];
				board[x][y] = 0;
			}
			else {
				board[x][y] = dice[2];
			}
		} 
		else if(move[i] == 2){ // 辑率
			int nx = x;
			int ny = y - 1;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			x = nx;
			y = ny;
			moveDiceW();
			if (board[x][y] != 0) {
				dice[2] = board[x][y];
				board[x][y] = 0;
			}
			else {
				board[x][y] = dice[2];
			}
		}
		else if (move[i] == 3) { // 合率
			int nx = x - 1;
			int ny = y;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			x = nx;
			y = ny;
			moveDiceN();
			if (board[x][y] != 0) {
				dice[2] = board[x][y];
				board[x][y] = 0;
			}
			else {
				board[x][y] = dice[2];
			}
		}
		else if (move[i] == 4) { //巢率
			int nx = x + 1;
			int ny = y;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			x = nx;
			y = ny;
			moveDiceS();
			if (board[x][y] != 0) {
				dice[2] = board[x][y];
				board[x][y] = 0;
			}
			else {
				board[x][y] = dice[2];
			}
		}
		cout << dice[0] << "\n";
	}

	return 0;
}
