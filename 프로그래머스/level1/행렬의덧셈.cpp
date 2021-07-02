//프로그래머스 행렬의 덧셈
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int row = arr1.size();
    int col = arr1[0].size();

    for (int i = 0; i < row; i++) {
        vector<int> temp;
        for (int j = 0; j < col; j++) {
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    vector<vector<int>> arr1 = { {1}, {2} };
    vector<vector<int>> arr2 = { {3}, {4} };

    solution(arr1, arr2);
    return 0;
}