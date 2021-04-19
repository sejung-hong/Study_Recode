//10799 ¼è¸·´ë±â
#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string pipe;
	cin >> pipe;

	stack <char> s;
	int num = 0;
	for (int i = 0; i < pipe.size(); i++) {
		if (pipe[i] == '(') {
			s.push(pipe[i]);
		}
		else if (pipe[i] == ')') {
			s.pop();
			if (pipe[i - 1] == '(')
				num += s.size();
			else
				num += 1;
		}
	}
	cout << num << endl;

	return 0;
}