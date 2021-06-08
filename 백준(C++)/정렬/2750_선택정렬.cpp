//2750 수 정렬하기 선택정렬
#include<iostream>
#include<vector>

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

	for (int i = 0; i < N; i++) {
		int min = 1001;
		int index = 0;
		for (int j = i; j < N; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}

		//swap
		int temp = arr[i];
		arr[i] = min;
		arr[index] = temp;
		
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}