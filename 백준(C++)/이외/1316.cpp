//1316 그룹 단어 체커
#include <iostream>
#include <cstring>
using namespace std;
bool visited[26] = { false, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int count = 0;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		int check = 0;
		memset(visited, false, sizeof(visited));
		visited[s[0]-97] = true;


		for (int j = 1; j < s.size(); j++) {
			if (s[j - 1] == s[j]) {
			}
			else {
				if (visited[s[j] - 97] == true)
					check = 1;
				else
					visited[s[j] - 97] = true;
			}
		}
		if (check == 0) {
			count++;
		}
	}

	cout << count << "\n";


	return 0;
}