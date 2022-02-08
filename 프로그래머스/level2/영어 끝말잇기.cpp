#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    unordered_map <string, int> um;

    int order = words.size() / n;

    string preWord = words[0];
    um[preWord]++;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            //이미 사용된 단어
            if (um[words[i * n + j]] != 0) {
                answer[0] = j + 1;
                answer[1] = i + 1;
                return answer;
            }
            //끝말잇기 x
            if (preWord[preWord.size() - 1] != words[i * n + j][0]) {
                answer[0] = j + 1;
                answer[1] = i + 1;
                return answer;
            }
            preWord = words[i * n + j];
            um[words[i * n + j]]++;
        }
    }

    return answer;
}