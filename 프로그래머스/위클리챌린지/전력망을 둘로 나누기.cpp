//���α׷��ӽ� ���¸��� �ѷ� ������
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000001;
    //����Ǿ��ִ� ��� vec�� ����
    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < wires.size(); i++) {
        vec[wires[i][0]].push_back(wires[i][1]);
        vec[wires[i][1]].push_back(wires[i][0]);
    }

    //wires �ϳ��� �����
    for (int i = 0; i < wires.size(); i++) {
        int size = 0;
        //����� ���� �ϳ��� ����� ��
        if (vec[wires[i][0]].size() == 1 || vec[wires[i][1]].size() == 1) {
            size = n - 2;
        }
        else {
            //BFS ���� �켱 Ž��
            queue<int> q;
            q.push(wires[i][0]);
            size++;
            //�湮 ��� Ȯ��
            bool visited[101] = { 0, };
            visited[wires[i][0]] = true;
            visited[wires[i][1]] = true;
            while (!q.empty()) {
                for (int j = 0; j < vec[q.front()].size(); j++) {
                    //�湮���� ���� ���
                    if (visited[vec[q.front()][j]] == false) {
                        q.push(vec[q.front()][j]); //����Ǿ��ִ� ��� push
                        visited[vec[q.front()][j]] = true; //�湮
                        size++;
                    }
                }
                q.pop();
            }
            size = abs(size - (n - size)); //����
        }
        answer = min(answer, size); //�ּڰ�
    }

    return answer;
}

int main() {
    int n = 9;
    vector<vector<int>> wires = { {1,3}, {2,3}, {3,4}, {4,5}, {4,6}, {4,7}, {7,8}, {7,9} };
    cout << solution(n, wires) << "\n";
    return 0;
}