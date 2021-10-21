//���� 1956 �
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//����ӵ� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	int graph[401][401] = { 0, };
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c; //a->b = c
	}

	//�÷��̵� �ͼ�(����Ŭã��)
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] != 0)
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); //�ּҰŸ�
					else
						graph[i][j] = graph[i][k] + graph[k][j];
				}
			}

		}
	}

	int answer = 10000000000; //max
	int check = 0;
	for (int i = 1; i <= V; i++) {
		if (graph[i][i] != 0) {
			answer = min(answer, graph[i][i]); //�ּ� ������ ����
			check = 1;
		}
	}

	if (check == 0)
		cout << "-1\n"; //����Ŭ�� ���� ���
	else
		cout << answer << "\n";


	return 0;
}

//�ɸ� �ð� : 30��