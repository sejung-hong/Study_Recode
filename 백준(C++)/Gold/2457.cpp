//���� 2457 ���ִ��� ����
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� �Ǵ� ��¥�� ���� ������ ����
bool cmp(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
	if (a[0].first == b[0].first) {
		return a[0].second < b[0].second;
	}
	return a[0].first < b[0].first;
}

//��¥ �� �� ū ��¥ return
pair<int, int> day_compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.first < b.first)
		return b;
	else if(a.first == b.first){
		if (a.second < b.second)
			return b;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�Է�
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> day;
	for (int i = 0; i < N; i++) {
		int s_m, s_d, e_m, e_d;
		cin >> s_m >> s_d >> e_m >> e_d;
		vector<pair<int, int>> v;
		v.push_back(make_pair(s_m, s_d));
		v.push_back(make_pair(e_m, e_d));
		day.push_back(v);
	}

	sort(day.begin(), day.end(), cmp); //����

	int count = 0;
	pair<int, int> temp_s = { 3,1 }; //3�� 1��
	pair<int, int> temp_e = { 12, 1 };
	pair<int, int> temp = { 1,1 };
	int check = 0;

	for (int i = 0; i < N; i++) {
		//���� ��ġ���� �������
		if (day_compare(temp_s, day[i][0]) == temp_s) {
			temp = day_compare(temp, day[i][1]);
			//11�� 30�� ����
			if (day_compare(temp, temp_e) == temp) {
				check = 1;
				break;
			}
		}
		//���� ��ġ���� ������ ��
		else {
			temp_s = temp; //���� ��ġ temp�� ����
			count++; //���� �ϳ� ����
			//���� ��ġ���� ���� ���� ��¥�� �տ� ���� �� 
			if (day_compare(temp_s, day[i][0]) == temp_s) {
				temp = day[i][1];
				//12�� 1�Ϻ��� ��¥�� ���� ��
				if (day_compare(temp, temp_e) == temp) {
					check = 1;
					break;
				}
			}
			//���� ��ġ���� ���� ���� ��¥�� �ڿ� ���� �� 
			else
				break;
		}
	}

	if (check == 0)
		cout << "0\n";
	else
		cout << count + 1 << "\n";


	return 0;
}