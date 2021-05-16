//1697 ¼û¹Ù²ÀÁú
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, K;
int time = 0;
bool visited[100001] = { false, };
void BFS() {
	queue <pair<int,int>> q;
	q.emplace(0, N);

	while (!q.empty()) {
		int next = q.front().second;
		visited[next] = true;
		if (next == K) {
			time = q.front().first;
			return;
		}
		int next_time = q.front().first + 1;

		if (next * 2 < 100001) {
			if (visited[next * 2] == false)
				q.emplace(next_time, next * 2);
		}
		if (next + 1 < 100001) {
			if (visited[next + 1] == false)
				q.emplace(next_time, next + 1);
		}
		if (next - 1 >= 0) {
			if (visited[next - 1] == false)
				q.emplace(next_time, next - 1);
		}

		q.pop();

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	if (N >= K) {
		time = (N - K);
	}
	else
		BFS();

	cout << time << "\n";

	return 0;
}