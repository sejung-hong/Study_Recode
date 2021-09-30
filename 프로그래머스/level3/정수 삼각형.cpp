//프로그래머스 정수 삼각형
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++) { //두번째 줄부터
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j - 1 < 0)
                triangle[i][j] += triangle[i - 1][j]; //오른쪽 위
            else if (j == i)
                triangle[i][j] += triangle[i - 1][j - 1]; //왼쪽 위
            else
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]); //오른쪽 위, 왼쪽 위 중 더 큰 값

        }
    }
    
    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end()); //바닥에서 가장 큰 수

    return answer;
}

int main() {
    vector<vector<int>> triangle = { {7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5} };
    cout << solution(triangle) << "\n";
    return 0;
}