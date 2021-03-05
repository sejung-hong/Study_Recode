//11000 ���ǽ� ����
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility> //pair ���� ���
#include <queue>
using namespace std;

int main() {
	int N;
	vector<pair <int, int>> schedule;
	cin >> N;

	int S, T;
	pair<int, int> p;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		p.first = S;
		p.second = T;
		schedule.push_back(p);
	}

	sort(schedule.begin(), schedule.end()); //����

	priority_queue<int, vector<int>, greater<int>> pq; //������������ ���ĵǴ� ť

	pq.push(schedule[0].second);

	for (int i = 1; i < N; i++) {
		if (pq.top() <= schedule[i].first)
			pq.pop();
		pq.push(schedule[i].second);
	}

	cout << pq.size() << endl;

	/*
	int room_num = 0;
	int end = 0;
	while (schedule.size() !=0) {
		int i = 0;
		end = 0;
		while (i < schedule.size()) {
			if (end <= schedule[i].first) {
				end = schedule[i].second;
				schedule.erase(schedule.begin() + i); //�ش��ϴ� ��ġ�� ���Ҹ� �����.
			}
			else
				i++;
		}
		room_num++;
	}

	cout << room_num << endl;
	*/
	return 0;
}