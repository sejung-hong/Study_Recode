//2750 Äü Á¤·Ä
#include<iostream>
using namespace std;

void quick_sort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && data[i] <= data[pivot]) {
			i++;
		}
		while (j > start && data[j] >= data[pivot]) {
			j--;
		}

		if (i > j) {
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

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

	quick_sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}