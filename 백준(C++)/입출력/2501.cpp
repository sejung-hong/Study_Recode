//2501 약수 구하기
#include <iostream>
using namespace std;

int main() {
	int N, K = 0; //N,K는 자연수
	cin >> N >> K;
	//0 < N <= 10000, 0 < K <=N 

	int divisor[10000] = { 0, }; //약수를 저장하는 배열 0으로 초기화

	int num = 0; //약수의 개수
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			divisor[num] = i; //약수 저장
			num++;
		}
	}

	if (num < K) { //K번째 약수가 존재하지 않을 경우
		cout << "0" << endl;
	}
	else
		cout << divisor[K-1] << endl; //배열은 0부터 저장되기 때문에 K-1번째 배열 출력

	return 0;
}