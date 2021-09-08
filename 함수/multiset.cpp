//multiset STL
#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset<int> s1; //오름차순 defalt
	multiset<int, greater<int>> s2; //내림차순
	//삽입
	s1.insert(2); s2.insert(2);
	s1.insert(3); s2.insert(3);
	s1.insert(4); s2.insert(4);
	s1.insert(3); s2.insert(3);
	s1.insert(3); s2.insert(3);
	s1.insert(1); s2.insert(1);

	//s1출력
	for (auto it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//s2 출력
	for (auto it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}