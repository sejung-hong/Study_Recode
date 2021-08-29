//프로그래머스 튜플
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

//size 내림차순으로 정렬
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;

    //숫자 찾기
    string num = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 48 && s[i] <= 57) {
            num += s[i];
        }
        else {
            if (!num.empty())
                m[stoi(num)] ++; // 숫자 1 증가
            num = "";
        }

    }

    vector <pair<int, int>> map_v(m.begin(), m.end()); //map vector로 변환

    sort(map_v.begin(), map_v.end(), cmp); //size 내림차순으로 정렬

    for (int i = 0; i < map_v.size(); i++) {
        answer.push_back(map_v[i].first);
    }

    return answer;
}

int main() {
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";

    solution(s);

    return 0;
}