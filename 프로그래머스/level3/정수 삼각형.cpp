//���α׷��ӽ� ���� �ﰢ��
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++) { //�ι�° �ٺ���
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j - 1 < 0)
                triangle[i][j] += triangle[i - 1][j]; //������ ��
            else if (j == i)
                triangle[i][j] += triangle[i - 1][j - 1]; //���� ��
            else
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]); //������ ��, ���� �� �� �� ū ��

        }
    }
    
    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end()); //�ٴڿ��� ���� ū ��

    return answer;
}

int main() {
    vector<vector<int>> triangle = { {7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5} };
    cout << solution(triangle) << "\n";
    return 0;
}