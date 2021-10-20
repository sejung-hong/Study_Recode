//백준 2776 암기왕
#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N;
		map<int, int> m; //해쉬 맵
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			m[num] = 1;
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			if (m[num] == 1) //존재할 때
				cout << "1\n";
			else //존재하지 않을 때
				cout << "0\n";
		}
	}
	return 0;
}