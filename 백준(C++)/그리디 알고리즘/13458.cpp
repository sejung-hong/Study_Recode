//13458 시험 감독
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> A;
	int B, C;

	cin >> N;
	
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.push_back(a);
	}
	cin >> B >> C;

	long long int people = 0;

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		people++;

		if (A[i] > 0) {
			people += A[i] / C;

			if (A[i] % C != 0)
					people++;
		}
	}

	cout << people << endl;
	
	return 0;
}