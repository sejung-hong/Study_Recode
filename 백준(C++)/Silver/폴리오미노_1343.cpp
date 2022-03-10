//1343 폴리오미노
#include <iostream>
#include <string>

using namespace std;

string OutputString(int NumX){
	string AB = "";
	if (NumX % 2 == 1) {
		return AB;
	}
	for (int i = 0; i < NumX / 4; i++) {
		AB += "AAAA";
	}
	for (int i = 0; i < (NumX % 4) / 2; i++) {
		AB += "BB";
	}

	return AB;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string input;
	cin >> input;

	int NumX = 0;
	string output = "";
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'X') {
			NumX++;
		}
		else {
			if (NumX != 0) {
				if (OutputString(NumX) == "") {
					output = "-1";
					break;
				}
				output += OutputString(NumX);

			}
			output += ".";
			NumX = 0;
		}
	}
	if (NumX != 0) {
		if (OutputString(NumX) == "") {
			output = "-1";
		}
		else {
			output += OutputString(NumX);
		}
	}

	cout << output << "\n";

	return 0;
}