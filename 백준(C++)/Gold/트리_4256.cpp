//백준 4256 트리
#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;
vector<int> inorder;
int n;

void postorder(int start, int end, int root) {
	for (int i = start; i < end; i++) {
		if (preorder[root] == inorder[i]) {
			postorder(start, i, root + 1);
			postorder(i + 1, end, root + 1 + i - start);
			cout << preorder[root] << " ";
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		preorder.clear();
		inorder.clear();

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			preorder.push_back(num);
		}
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			inorder.push_back(num);
		}
		postorder(0, n, 0);
		cout << "\n";

	}
	return 0;
}