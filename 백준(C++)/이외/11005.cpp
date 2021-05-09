//11005 진법 변환2
#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	int B;
	stack <char> s;
	char c;
	
	cin >> N >> B;
	while (N > 0) {
		c = N % B;
		N /= B;

		if (c >= 10) {
			s.push(c + 55);
		}
		else
			s.push(c + 48);
	}


	while (s.size()) {
		cout << s.top();
		s.pop();
	}
	cout << "\n";
	return 0;
}