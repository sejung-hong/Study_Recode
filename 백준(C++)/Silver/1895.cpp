//���� 1895 ����
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�Է�
	int R, C; // ��,��
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
			} //���� 3x3��ŭ push

			sort(v.begin(), v.end()); //����

			if (v[4] >= T) // �߾Ӱ� T�� ��
				ans++;
		}
	}
	
	cout << ans << "\n";


	return 0;
}

//�ɸ��ð� : 15��
