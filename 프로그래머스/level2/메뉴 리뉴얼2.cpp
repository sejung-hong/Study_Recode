//프로그래머스 메뉴 리뉴얼
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map <string, int> m;

void combination(string order, string s, int n) {
    if (s.size() == n)
        m[s]++;
    else {
        for (int i = 0; i < order.size(); i++) {
            combination(order.substr(i + 1), s + order[i], n);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }//order정렬

    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++) {
            combination(orders[j], "", course[i]);
        }
        int num = 0;
        for (auto it : m) {
            num = max(num, it.second);
        }
        for (auto it : m) {
            if (num >= 2 && it.second == num)
                answer.push_back(it.first);
        }
        m.clear();
    }

    return answer;
}

int main() {
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2,3,4 };
    solution(orders, course);
    return 0;
}