//¹éÁØ 6987 ¿ùµåÄÅ
#include <iostream>
#include <vector>

using namespace std;

const int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
const int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

int score[6][3];
int match[6][3];
int result[4];
int t;

void DFS(int count) {
	if (count == 15) {
		if (result[t]) {
			return;
		}
		
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (score[i][j] != match[i][j]) {
					return;
				}
			}
		}
		
		result[t] = 1;

		return;
	}
	
	int t1 = team1[count];
	int t2 = team2[count];

	// t1 ½Â, t2 ÆĞ
	match[t1][0]++; match[t2][2]++;
	DFS(count + 1);
	match[t1][0]--; match[t2][2]--;

	// t1 ¹«, t2 ¹«
	match[t1][1]++; match[t2][1]++;
	DFS(count + 1);
	match[t1][1]--; match[t2][1]--;

	// t1 ÆĞ, t2 ½Â
	match[t1][2]++; match[t2][0]++;
	DFS(count + 1);
	match[t1][2]--; match[t2][0]--;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (t = 0; t < 4; t++) {
		for (int i = 0; i < 6; i++) {
			int w, t, l;
			cin >> w >> t >> l;
			score[i][0] = w;
			score[i][1] = t;
			score[i][2] = l;
		}
		validation = false;
		DFS(0);

	}

	for (int i = 0; i < 4; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}