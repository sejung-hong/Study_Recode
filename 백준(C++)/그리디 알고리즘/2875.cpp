//2875 대회 or 인턴
#include <iostream>
using namespace std;

int main() {
	int N, M, K;
	//N: 여학생 수
	//M: 남학생 수 
	//K: 인턴쉽에 참여해야하는 인원
	cin >> N >> M >> K;

	int team = 0;

	if (N / 2 <= M){
		team = N / 2;
	}
	else if (N / 2 > M) {
		team = M;
	}
	//인턴쉽을 고려하지 않고 만들 수 있는 팀

	K = K - (N - team * 2) - (M - team);

	if (K > 0) {
		if (K % 3 == 0) {
			team -= K / 3;
		}
		else {
			team = team - (K / 3) - 1;
		}
	}

	cout << team << endl;

	return 0;
}
//두명이 여학생과 1명의 남학생