//2331 ºÐÇØÇÕ
#include <iostream>
using namespace std;

int p;
int visited[1000000] = { false, };

void DFS(int n) {

	visited[n]++;
	if (visited[n] == 3) {
		return;
	}
	int sum = 0;
	while (n){
		sum += (int)pow((n % 10), p);
		n /= 10;
	}
	DFS(sum);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	return 0;
}