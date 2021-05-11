//2331 반복순열
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
int P;
int visited[300000] = { 0, };
vector <int> v;

void DFS(int A) {
	visited[A]++;

	if (visited[A] == 2) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == A) {
				cout << i << "\n";
				return;
			}
		}
	}
	
	int num = 0;
	while (A > 0) {
		num += pow((A % 10), P);
		A /= 10;
	}

	v.push_back(num);
	DFS(num);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A;
	cin >> A >> P;

	v.push_back(A);

	DFS(A);

	return 0;
}