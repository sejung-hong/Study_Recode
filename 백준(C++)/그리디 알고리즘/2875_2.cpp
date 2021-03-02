//2875 대회 or 인턴
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M, K;
	//N: 여학생 수
	//M: 남학생 수 
	//K: 인턴쉽에 참여해야하는 인원
	cin >> N >> M >> K;

	cout << min(min(N / 2, M), (N + M - K)/3) << endl;

	return 0;
}