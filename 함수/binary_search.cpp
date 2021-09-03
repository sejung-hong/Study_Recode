#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	if (binary_search(arr, arr + 10, 3)) {
		cout << "3 존재\n";
	}
	else {
		cout << "3 존재하지 않음\n";
	}
	
	if (binary_search(arr, arr + 10, 10)) {
		cout << "10 존재\n";
	}
	else {
		cout << "10 존재하지 않음\n";
	}

	return 0;
}