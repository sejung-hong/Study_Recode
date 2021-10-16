//���� 16401 ���� �����ֱ�
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�Է�
	int M, N;
	vector<int> L;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		L.push_back(l);
	}

	//�̺�Ž��, ����Ž��
	int left = 1, right = *max_element(L.begin(), L.end());
	//left: ���� ���� ��, right: ���� ū ��
	int sum = 0;
	while (left <= right) {
		int mid = (left + right) / 2; //�߾Ӱ�
		int count = 0;
		for (int i = 0; i < N; i++) {
			count += L[i] / mid; //mid ���� ���̷� �����ټ� �ִ� ��
		}
		if (count >= M) { //���� �����ټ� ���� ��
			left = mid + 1;
			sum = mid;
		}
		else if (count < M) { //���� �����ټ� ���� ��
			right = mid - 1;
		}
	}
	cout << sum << "\n";

	return 0;
}