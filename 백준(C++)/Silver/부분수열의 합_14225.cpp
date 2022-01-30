//백준 14225 부분수열의 합
#include <iostream>
#include <vector>

using namespace std;

bool visited[2000001] = { false, };
vector<int> S;
int N;

void DFS(int i, int sum) {
	visited[sum] = true;
	if (i == N)
		return;
	else {
		DFS(i + 1, sum);
		DFS(i + 1, sum + S[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		S.push_back(num);
	}

	DFS(0, 0);

	int num = 1;
	while (1) {
		if (visited[num] == false) {
			cout << num << "\n";
			break;
		}
		num++;
	}
	
	return 0;
}