//1158 요세푸스 문제
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector <int>vec;
	for (int i = 1; i <= N; i++) {
		vec.push_back(i);
	}
	
	cout << "<";

	int remove = -1;
	int num = K - 1;
	while (vec.size()) {
		if (vec.size() == N) {
			cout << vec[num];
			vec.erase(vec.begin() + num);
			continue;
		}

		num += (K - 1);
		while (vec.size() <= num) {
			num -= vec.size();
		}
		cout << ", " << vec[num];
		vec.erase(vec.begin() + num);

	}

	cout << ">" << "\n";

	return 0;
}