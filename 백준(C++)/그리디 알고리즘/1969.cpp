//1969 DNA
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
char DNA[1000][50];  //��Ŭ����Ƽ�� ��
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	//ù ��° ���� ���ٸ�
	if (a.first == b.first)
		return a.second < b.second; //�� ��° ���� ��������
	return a.first > b.first; //ù ��° ���� �� ���� ���� ������ ��������
}

int main() {
	int N, M;
	char s[50];
	int sum = 0;
	vector <pair<int, char>> dna; //��Ŭ����Ƽ�� �ϳ�
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> DNA[i];
	}

	int check_dna = 0; 
	for (int i = 0; i < M; i++) {
		dna.clear();
		for (int j = 0; j < N; j++) {
			check_dna = 0;
			for (int k = 0; k < dna.size(); k++) {
				if (dna[k].second == DNA[j][i]) {
					dna[k].first++; //size ����
					check_dna = 1;
					break;
				}
			}
			if (check_dna == 0) {
				dna.push_back(make_pair(1, DNA[j][i])); // dna�� �ϳ� �����Ͽ� ����
			}
		}

		if (dna.size() == 1) {
			s[i] = dna[0].second; // �������� dna�� ������ ��
			continue;
		}

		sort(dna.begin(), dna.end(), compare); //������������ ����

		s[i] = dna[0].second;
		sum += (N - dna[0].first);
	}

	for (int i = 0; i < M; i++) {
		cout << s[i];
	}

	cout << endl << sum << endl;

	return 0;
}