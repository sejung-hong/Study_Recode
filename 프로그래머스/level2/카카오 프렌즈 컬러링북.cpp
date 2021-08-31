//���α׷��ӽ� īī�� ������ �÷�����
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
bool visited[101][101];
int ni[4], nj[4];
int m_copy;
int n_copy;
int size_of_one_area;


void DFS(int cur_i, int cur_j, vector<vector<int>>& picture) {
    visited[cur_i][cur_j] = true;
    size_of_one_area++;

    for (int i = 0; i < 4; i++) {
        int next_i = cur_i + ni[i];
        int next_j = cur_j + nj[i];
        if (next_i < 0 || next_i >= m_copy || next_j < 0 || next_j >= n_copy)
            continue;
        if (visited[next_i][next_j] == false && picture[next_i][next_j] == picture[cur_i][cur_j]) {
            DFS(next_i, next_j, picture);
        }
    }

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    //�������� �ʱ�ȭ
    memset(visited, 0, sizeof(visited));
    ni[0] = 1; ni[1] = 0; ni[2] = -1; ni[3] = 0;
    nj[0] = 0; nj[1] = 1; nj[2] = 0; nj[3] = -1;
    m_copy = m;
    n_copy = n;
    size_of_one_area = 0;

    for (int i = 0; i < m; i++) { //����
        for (int j = 0; j < n; j++) { //����
            if (picture[i][j] != 0 && visited[i][j] == false) {
                size_of_one_area = 0;
                DFS(i, j, picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, size_of_one_area);
            }
                
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = { {1,1,1,0}, {1,2,2,0}, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3} };
    solution(m, n, picture);
    return 0;
}