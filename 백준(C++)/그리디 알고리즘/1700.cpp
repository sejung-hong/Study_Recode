//1700 ��Ƽ�� �����ٸ�
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int N, K; //N: ��Ƽ�Ǳ����� ����, K: ���� ��ǰ�� �� ���Ƚ��
	cin.tie(0); //cin ����ӵ� ���
	cin >> N >> K;

	vector <int> product;
	vector <int> plug;

	int plug_out = 0; //���� ���

	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		product.push_back(num);
	} // �����ǰ ������� �Է�


	vector<int>::iterator iter; //�ݺ���

	plug.push_back(product[0]); //ó�� ��ǰ plug in

	int plug_check;
	for (int i = 1; i < K; i++) {
		plug_check = 0;
		for (iter = plug.begin(); iter != plug.end(); ++iter) {
			if (product[i] == *iter) {
				plug_check = 1; //�̹� ��ǰ�� ���� ���� ��
				break;
			}
		}
		if (plug_check == 1)
			continue;

		if (plug.size() != N) { //�ڸ��� ������ ��
			plug.push_back(product[i]);
			continue;
		}

		//�÷��׸� �̾ƾ��� ��
		int out_location = 0; //�̾ƾ��� ��ġ
		int product_location = -1; // ��ǰ ��ġ
		int compare = -1; // ��

		for (int M = 0; M < N; M++) {
			product_location = -1;
			for (int j = i + 1; j < K; j++) {
				if (plug[M] == product[j]) {
					product_location = j;
					break;
					}
			}

			//�������� ������ �ʴ� ��ǰ
			if (product_location == -1) {
				out_location = M;
				break;
			}

			//���� ���߿� ���Ǿ���� ��ǰ ����
			if (compare < product_location) {
				out_location = M;
				compare = product_location;
			}
		}

		plug[out_location] = product[i]; //��ǰ out, ���� ��ǰ in
		plug_out++;
	}

	cout << plug_out << endl;
	return 0;
}