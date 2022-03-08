//백준 5639 이진 검색 트리
#include <iostream>
#include <vector>

using namespace std;

vector<int> preOrder;

struct node
{
	node* left;
	node* right;
	int value;
	
};

void postOrder(int node) {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num;
	while (cin >> num) {
		preOrder.push_back(num);
	}

	postOrder(0);

	return 0;
}