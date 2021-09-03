#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[10] = { 0, 1, 1, 2, 2, 4, 4, 5, 5, 6 };

	auto it2 = lower_bound(arr, arr + 10, 2);
	cout << "location : "<< it2 - arr << "\n"; // 출력 : 3
	cout << "num : " << arr[it2 - arr] << "\n"; // 출력 : 2

	auto it3 = lower_bound(arr, arr + 10, 3);
	cout << "location : " << it3 - arr << "\n"; // 출력: 5
	cout << "num : " << arr[it3 - arr] << "\n"; // 출력: 4

	return 0;
}