//프로그래머스 메뉴 리뉴얼
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if(a.first.size() == b.first.size())
        return a.second > b.second; //조합 순으로 내림차순 정렬
    return a.first.size() > b.first.size(); //string size 내림차순
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map <string, int> m;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int i = 0; i < orders.size(); i++) {
        //비트 마스킹
        for (int j = 1; j < (1 << orders[i].size()); j++) {
            string menu = "";
            for (int k = 0; k < orders[i].size(); k++) {
                if (j & (1 << k)) {
                    menu += orders[i][k]; //조합 구성
                }
            }
            for (int l = 0; l < course.size(); l++) {
                if (course[l] == menu.size()) {
                    m[menu] += 1; // 구성 1증가
                    break;
                }
            }
        }
    }

    vector <pair<string, int>> vec(m.begin(), m.end()); //map vector로 copy

    sort(vec.begin(), vec.end(), cmp); //정렬

    int string_size = 20; //최대
    int string_count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].second == 1) //조합이 한개 있을 때
            continue;
        if (string_size > vec[i].first.size()) { //string 중 가장 최대 조합
            string_size = vec[i].first.size();
            string_count = vec[i].second;
            answer.push_back(vec[i].first);
            continue;
        }
        if (string_count == vec[i].second) //최대 조합 개수가 같을때
            answer.push_back(vec[i].first);
    }

    sort(answer.begin(), answer.end()); //출력 정렬
    return answer;
}

int main() {
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2,3,4 };
    solution(orders, course);
    return 0;
}