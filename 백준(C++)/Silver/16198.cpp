//백준 16198 에너지 모으기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m = 0;

//재귀
void energy(vector<int>& v, int ans) {
	//사이즈가 3일 때 return 
	if (v.size() == 3) {
		ans += v[0] * v[2];
		m = max(m, ans);
		return;
	}

	//구할 수 있는 모든 에너지
	for (int i = 0; i < v.size() - 2; i++) {
		vector<int> v_copy = v;
		v_copy.erase(v_copy.begin() + i + 1); //구슬 제거
		energy(v_copy, ans + (v[i] * v[i + 2])); //구슬 제거 후 에너지 모으기
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	energy(v, 0); //모든 경우의 수

	cout << m << "\n";

	return 0;
}

//걸린시간 : 50분