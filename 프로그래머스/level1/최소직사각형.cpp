//프로그래머스 최소직사각형
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int max_col = 0;
    int max_row = 0;
    for (int i = 0; i < sizes.size(); i++) {
        max_col = max(max_col, min(sizes[i][0], sizes[i][1]));
        max_row = max(max_row, max(sizes[i][0], sizes[i][1]));
    }

    answer = max_col * max_row;

    return answer;
}

int main() {
    vector<vector<int>> sizes = { {60,50}, {30,70}, {60,30}, {80,40} };
    cout << solution(sizes) << "\n";
    return 0;
}