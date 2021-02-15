//11718
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;

	while (getline(cin, str)) {
		if (str == "")
			break;
		cout << str << endl;
	}

	return 0;
}