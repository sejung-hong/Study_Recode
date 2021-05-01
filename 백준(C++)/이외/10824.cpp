#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B, C, D;

	cin >> A >> B >> C >> D;

	string A_B = A + B;
	string C_D = C + D;

	long long A_B_int, C_D_int;
	
	A_B_int = stoll(A_B);
	C_D_int = stoll(C_D);

	cout << A_B_int + C_D_int << "\n";
	return 0;
}