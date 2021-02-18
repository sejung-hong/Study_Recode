//10818 최소,최대
#include <iostream>
using namespace std;
int arr[1000000];

int main() {
	
	int N;
	cin >> N;

	int min = 1000000;
	int max = -1000000;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	cout << min << " " << max << endl;

	return 0;
}