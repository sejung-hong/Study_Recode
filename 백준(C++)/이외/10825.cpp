// 10825 ������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//����ü
struct Person {
	string name;
	int korea;
	int english;
	int math;
};

//�� ����ü�� ���ϴ� �Լ�
bool compare(const Person& a, const Person& b) {
	if (a.korea == b.korea) { //�������� ���� ���
		if (a.english == b.english) { //�������� ���� ���
			if (a.math == b.math) //�������� ���� ���
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
	//cin, cout �ӵ� ���

	int N;
	cin >> N;

	vector <Person> vec;

	struct Person p;
	for (int i = 0; i < N; i++) {
		cin >> p.name >> p.korea >> p.english >> p.math;
		vec.push_back(p);
	}//�Է�

	sort(vec.begin(), vec.end(), compare); //����

	for (int i = 0; i < N; i++) {
		cout << vec[i].name << "\n";
	} //���

	return 0;
}