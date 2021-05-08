//1¹ø
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	stack <int> result;
	int location = 0;
	while (s[location]){
		if (s[location] > 65) {

			if (s[location] == 'z') {
				result.push(0);
				location += 4;
			}
			else if (s[location] == 'o') {
				result.push(1);
				location += 3;
			}
			else if (s[location] == 't') {
				location++;
				if (s[location] == 'w') {
					result.push(2);
					location += 2;
				}
				else {
					result.push(3);
					location += 4;
				}

			}
			else if (s[location] == 'f') {
				location++;
				if (s[location] == 'o') {
					result.push(4);
					location += 3;
				}
				else {
					result.push(5);
					location += 3;
				}
			}
			else if (s[location] == 's') {
				location++;
				if (s[location] == 'i') {
					result.push(6);
					location += 2;
				}
				else {
					result.push(7);
					location += 4;
				}
			}
			else if (s[location] == 'e') {
				result.push(8);
				location += 5;
			}
			else if (s[location] == 'n') {
				result.push(9);
				location += 4;
			}

		}
		else {
			result.push(s[location]-48);
			location++;
		}
	}

	int answer = 0;
	int ten = 1;

	while (!result.empty()) {
		answer += result.top() * ten;
		ten *= 10;
		result.pop();
	}

	cout << answer << "\n";

	return 0;
}