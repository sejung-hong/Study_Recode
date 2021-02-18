//2460 지능형 기차2
#include <iostream>
using namespace std;

int main() {
	int Get_on[10]; //기차에 오른사람
	int Get_off[10]; //기차에 내린사람
	int max = 0;
	int people = 0;

	for (int i = 0; i < 10; i++) {
		cin >> Get_on[i] >> Get_off[i];
		people = Get_off[i] - Get_on[i] + people;
		if (max < people)
			max = people;
	}

	cout << max << endl;

	return 0;
}