//프로그래머스 신고 결과 받기
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_map<string, int>> um;
    unordered_map<string, int> report_id;

    for (int i = 0; i < report.size(); i++) {
        stringstream ss(report[i]);
        string s1, s2;
        ss >> s1 >> s2;

        um[s1][s2]++;
        if (um[s1][s2] == 1) {
            report_id[s2]++; //한 유저가 처음 신고한 경우
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        int num = 0;
        for (auto m : um[id_list[i]]) {
            if (report_id[m.first] >= k) {
                num++;
            }
        }
        answer.push_back(num);
    }

    return answer;
}

int main() {
    vector<string> id_list = { "con", "ryan" };
    vector<string> report = { "ryan con", "ryan con", "ryan con", "ryan con" };
    int k = 3;

    solution(id_list, report, k);

}