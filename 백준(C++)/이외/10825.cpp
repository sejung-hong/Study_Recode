// 10825 국영수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//구조체
struct Person {
	string name;
	int korea;
	int english;
	int math;
};

//두 구조체를 비교하는 함수
bool compare(const Person& a, const Person& b) {
	if (a.korea == b.korea) { //국어점수 같을 경우
		if (a.english == b.english) { //영어점수 같을 경우
			if (a.math == b.math) //수학점수 같을 경우
				return a.name < b.name;
			return a.math > b.math;
		}
		return a.english < b.english;
	}
	return a.korea > b.korea;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//cin, cout 속도 향상

	int N;
	cin >> N;

	vector <Person> vec;

	struct Person p;
	for (int i = 0; i < N; i++) {
		cin >> p.name >> p.korea >> p.english >> p.math;
		vec.push_back(p);
	}//입력

	sort(vec.begin(), vec.end(), compare); //정렬

	for (int i = 0; i < N; i++) {
		cout << vec[i].name << "\n";
	} //출력

	return 0;
}