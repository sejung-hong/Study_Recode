//프로그래머스 K번째수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> tok;
        for (int j = commands[i][0]-1; j < commands[i][1]; j++) {
            tok.push_back(array[j]);
        }

        sort(tok.begin(), tok.end());//오름차순 정렬

        answer.push_back(tok[commands[i][2] - 1]); //k번쨋 저장
    }

    return answer;
}

int main() {
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> command = { {2,5,3},{4,4,1}, {1,7,3} };

    vector <int> answer = solution(array, command);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
