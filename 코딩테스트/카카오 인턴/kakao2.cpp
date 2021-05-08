//카카오 2번
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
bool visited[6][6] = { false, };
vector<string> place1;
int nx[4] = { -1, 0, 1, 0 }, ny[4] = { 0, 1, 0, -1 };
int check = 0;

//BFS 넓이 우선탐색
void BFS(int i, int j) {
	check = 0;
	visited[i][j] = true; //방문:ture
	queue<pair<pair<int,int>, int>> q;

	int size = 0;
	q.push(make_pair(make_pair(i, j),size));

	while (!q.empty()) {
		i = q.front().first.first;
		j = q.front().first.second;
		size = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int next_x = i + nx[k];
			int next_y = j + ny[k];
			if (next_x < 0 || next_y < 0 || next_x >= 5 || next_y >= 5) {
				continue;
			}
			if (visited[next_x][next_y] == false && place1[next_x][next_y] != 'X') {
				visited[next_x][next_y] = true;
				q.push(make_pair(make_pair(next_x, next_y), size + 1));
				if (size + 1 < 3 && place1[next_x][next_y] == 'P') {
					check = 1;
					return;
				}

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> answer;

	vector<vector<string>> places(5);

	string s;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> s;
			places[i].push_back(s);
		}
	}

	for (int i = 0; i < 5; i++) {
		place1 = places[i];

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (place1[i][j] == 'P') {
					memset(visited, 0, sizeof(visited));
					BFS(i, j);
					if (check == 1) {
						break;
					}
				}
			}
			if (check == 1) {
				answer.push_back(0);
				break;
			}
		}
		if (check == 0) {
			answer.push_back(1);
		}

	}
		for (int i = 0; i < 5; i++) {
			cout << answer[i] << endl;
		}

	return 0;
}