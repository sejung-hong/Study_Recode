//프로그래머스 로또의 최고 순위와 최저 순위
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    unordered_map<int, int> m;

    int lucky = 0;
    for (int i = 0; i < lottos.size(); i++) {
        m[lottos[i]]++;
    }

    for (int i = 0; i < win_nums.size(); i++) {
        if (m.find(win_nums[i])==m.end()) { //못찾은경우
            lucky++;
        }
        else {
            m[win_nums[i]]--;
        }
    }

    if ((lucky + 1 - m[0]) >= 6)
        answer.push_back(6);
    else
        answer.push_back(lucky + 1 - m[0]);

    if ((lucky + 1) >= 6)
        answer.push_back(6);
    else
        answer.push_back(lucky + 1);

    return answer;
}

int main() {
    vector<int> a = { 45, 4, 35, 20, 3, 9 };
    vector<int> b = { 20, 9, 3, 45, 4, 35 };

    cout << solution(a, b)[0] << "\n";
    cout << solution(a, b)[1] << "\n";
    return 0;
}