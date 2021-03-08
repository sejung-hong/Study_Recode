//1931 ȸ�ǽ� ����
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N;
	vector <pair<int, int>> meeting;

	cin >> N;
	pair<int, int> meet;
	for (int i = 0; i < N; i++) {
		cin >> meet.second >> meet.first; //������ �ð��� �������� ����
		meeting.push_back(meet);
	}

	sort(meeting.begin(), meeting.end()); //������������

	int count = 0;
	int compare = 0;
	int start, end;
	for (int i = 0; i < N; i++) {
		start = meeting[i].second;
		end = meeting[i].first;
		if (compare <= start){
			compare = end;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}