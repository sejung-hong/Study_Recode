//9012 °ýÈ£
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		stack <char> s;
		string VPS;
		cin >> VPS;

		for (int j = 0; j < VPS.length(); j++)
		{
			if (s.empty() || VPS[j] == '(')
				s.push(VPS[j]);
			else if (s.top() == '(' && VPS[j] == ')')
				s.pop();
		}

		if (s.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}