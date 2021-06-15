//2750 »ğÀÔÁ¤·Ä
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int arr[1001];

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[i] = num;
	}


	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				int temp = arr[i];
				for(int k = i; k > j; k--) {
					arr[k] = arr[k - 1];
				}
				arr[j] = temp;
			}
		}
	}


	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}