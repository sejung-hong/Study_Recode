//2667 단지번호붙이기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int house[26][26] = { 0, };
bool visited[26][26] = { 0, };
int N;
int nx[4] = { 1,0, -1, 0 }, ny[4] = { 0, 1, 0, -1 };
int num_complex = 0;
int num_house = 0;

void DFS(int x, int y) {
	visited[x][y] = true;
	num_house++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + nx[i];
		int next_y = y + ny[i];
		if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) {
			continue;
		}
		if (house[next_x][next_y] == 1 && visited[next_x][next_y] == false) {
			DFS(next_x, next_y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			house[i][j] = s[j] - 48;
		}
	}

	vector <int> v;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] != 0 && visited[i][j] == 0) {
				num_complex++;
				num_house = 0;
				DFS(i, j);
				v.push_back(num_house);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << num_complex << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	
	return 0;
}