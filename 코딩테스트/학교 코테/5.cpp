// 5:사다리 타기
#include <iostream>
#include <stack>
#include <queue>
#include<cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int start, end;
	cin >> start >> end;

	int A, B;
	cin >> A >> B; //제거A 추가 B

	queue <int> q; //가로 사다리
	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		q.push(num);
	}

	stack <int> s;
	s.push(start);
	int move = start;
	while (!q.empty()){
		if (move == q.front()) {
			move++;
			s.push(move);
		}
		else if((move - 1) == q.front()){
			move--;
			s.push(move);
		}
		q.pop();
	}

	int add;
	add = abs(s.top() - end) * B;

	int remove = 0;
	int check = 0;
	while (!s.empty()){
		if (s.top() == end) {
			check = 1;
			break;
		}
		remove++;
		s.pop();
	}
	remove = remove * A;

	if (remove >= add || check == 1) {
		cout << add << "\n";
	}
	else {
		cout << remove << "\n";
	}



	return 0;
}