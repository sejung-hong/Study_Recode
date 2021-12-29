//���� 17070 ������ �ű��1
#include <iostream>

using namespace std;

int N;
int board[17][17];
int way = 0;

bool isBoard(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N) {
		return false;
	}
	return true;
}

void DFS(int i, int j, int pipeDirection) {
	if (i == N - 1 && j == N - 1) {
		way++;
		return;
	}
	//������ ����
	if (pipeDirection == 0) {
		//���η� �̵�
		if (isBoard(i, j + 1) == true) {
			if (board[i][j + 1] == 0) {
				DFS(i, j + 1, 0);
			}
		}
		//�밢������ �̵�
		if (isBoard(i + 1, j + 1) == true) {
			if (board[i][j + 1] == 0 && board[i + 1][j] == 0 && board[i + 1][j + 1] == 0) {
				DFS(i + 1, j + 1, 2);
			}
		}
	}
	//������ ����
	else if (pipeDirection == 1) {
		//���η� �̵�
		if (isBoard(i+1, j) == true) {
			if (board[i + 1][j] == 0) {
				DFS(i + 1, j, 1);
			}
		}
		//�밢������ �̵�
		if (isBoard(i + 1, j + 1) == true) {
			if (board[i + 1][j] == 0 && board[i][j + 1] == 0 && board[i + 1][j + 1] == 0) {
				DFS(i + 1, j + 1, 2);
			}
		}
	}
	//������ �밢��
	else if (pipeDirection == 2) {
		//���η� �̵�
		if (isBoard(i, j + 1) == true) {
			if (board[i][j + 1] == 0) {
				DFS(i, j + 1, 0);
			}
		}
		//���η� �̵�
		if (isBoard(i + 1, j) == true) {
			if (board[i + 1][j] == 0) {
				DFS(i + 1, j, 1);
			}
		}
		//�밢������ �̵�
		if (isBoard(i + 1, j + 1) == true) {
			if (board[i + 1][j] == 0 && board[i][j + 1] == 0 && board[i + 1][j + 1] == 0) {
				DFS(i + 1, j + 1, 2);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			board[i][j] = num;
		}
	}

	DFS(0, 1, 0);
	cout << way << "\n";

	return 0;
}