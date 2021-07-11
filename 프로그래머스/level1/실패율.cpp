//프로그래머스 실패율
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first)
        return a.second < b.second; //실패율이 같을 때 stage 순
    return a.first > b.first; //실패율 내림차순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail;

    for (int i = 1; i <= N; i++) {
        double fail_people = 0.0;
        double people = 0.0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] >= i) {
                people++;
                if (stages[j] <= i)
                    fail_people++;
            }
        }
        if (people == 0) {
            fail.push_back(make_pair(0, i));
        }
        else {
            fail.push_back(make_pair(fail_people / people, i));
        }
    }

    sort(fail.begin(), fail.end(), compare); //내림차순

    for (int i = 0; i < N; i++) {
        answer.push_back(fail[i].second);
    }

    return answer;
}

int main() {
    int N = 5;
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

    solution(N, stages);

    return 0;
}