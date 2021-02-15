//1924
#include <iostream>
using namespace std;

int main() {
	int x, y;
	int day = 0;
	int month[12] = { 31,28, 31, 30, 31, 30,31,31,30, 31, 30, 31 };
	string week[7] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT" };
	cin >> x >> y;

	for (int i = 0; i < x-1; i++) {
		day += month[i];
	}
	day += y;
	
	day %= 7;

	cout << week[day] << endl;

	return 0;
}