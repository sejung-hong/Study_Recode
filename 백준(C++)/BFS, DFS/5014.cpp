//5014 ��ŸƮ ��ũ
#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D;
int visited[1000001] = { 0, };

void BFS() {
	queue <int> q;
	q.push(S);
	visited[S] = 1; //ó�� ��ġ 1

	while (!q.empty()) {
		int floor = q.front();

		if (floor == G) { // �ش� ���� ����
			cout << visited[floor] -1 << "\n"; //������ 1�̹Ƿ�
			return;
		}
		
		int next;
		
		next = floor + U;
		if (visited[next] == 0 && next <= F) {
			q.push(next); //q�� ����
			visited[next] = visited[floor] + 1; //���� �����κ��� �Ÿ� +1
		}

		next = floor - D;
		if (visited[next] == 0 && next > 0) {
			q.push(next); //q�� ����
			visited[next] = visited[floor] + 1; //���� �����κ��� �Ÿ� +1
		}

		q.pop();
	}

	cout << "use the stairs\n"; //�̵��� �� ���� ��

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	BFS();

	
	return 0;
}