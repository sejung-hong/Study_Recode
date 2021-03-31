//1700 멀티탭 스케줄링
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int N, K; //N: 멀티탭구멍의 개수, K: 전기 용품의 총 사용횟수
	cin.tie(0); //cin 실행속도 향상
	cin >> N >> K;

	vector <int> product;
	vector <int> plug;

	int plug_out = 0; //최종 출력

	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		product.push_back(num);
	} // 전기용품 순서대로 입력


	vector<int>::iterator iter; //반복자

	plug.push_back(product[0]); //처음 용품 plug in

	int plug_check;
	for (int i = 1; i < K; i++) {
		plug_check = 0;
		for (iter = plug.begin(); iter != plug.end(); ++iter) {
			if (product[i] == *iter) {
				plug_check = 1; //이미 용품이 꽂혀 있을 때
				break;
			}
		}
		if (plug_check == 1)
			continue;

		if (plug.size() != N) { //자리가 남았을 때
			plug.push_back(product[i]);
			continue;
		}

		//플러그를 뽑아야할 때
		int out_location = 0; //뽑아야할 위치
		int product_location = -1; // 용품 위치
		int compare = -1; // 비교

		for (int M = 0; M < N; M++) {
			product_location = -1;
			for (int j = i + 1; j < K; j++) {
				if (plug[M] == product[j]) {
					product_location = j;
					break;
					}
			}

			//다음번에 사용되지 않는 용품
			if (product_location == -1) {
				out_location = M;
				break;
			}

			//제일 나중에 사용되어야할 제품 선택
			if (compare < product_location) {
				out_location = M;
				compare = product_location;
			}
		}

		plug[out_location] = product[i]; //용품 out, 다음 용품 in
		plug_out++;
	}

	cout << plug_out << endl;
	return 0;
}