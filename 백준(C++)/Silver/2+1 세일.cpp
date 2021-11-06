//백준 2+1 세일
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector <int> price;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		price.push_back(num);
	}

	sort(price.begin(), price.end(), greater<int>()); //내림차순

	int sum = 0;
	for (int i = 0; i < N; i ++) {
		//+1 무료
		if(i%3 != 2)
			sum += price[i];
	}

	cout << sum << "\n";

	return 0;
}