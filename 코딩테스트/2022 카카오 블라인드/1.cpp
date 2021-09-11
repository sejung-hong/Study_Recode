#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector <string> stop;
    map<string, vector<string>> m;

    for (int i = 0; i < report.size(); i++) {
        stringstream ss(report[i]);
        string singoid, stopid;
        ss >> singoid >> stopid;
        //이미 신고하지 않았을때
        if(find(m[stopid].begin(), m[stopid].end(), singoid) == m[stopid].end())
            m[stopid].push_back(singoid); //신고아이디 push
    }

    for (int i = 0; i < id_list.size(); i++) {
        int num = 0;
        for (auto v : m) {
            if (v.second.size() < k)
                continue;
            if (find(v.second.begin(), v.second.end(), id_list[i]) !=v.second.end()) {
                num++;
            }//find
        }
        answer.push_back(num);
    }

    return answer;
}

int main() {
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    int k = 2;
    solution(id_list, report, k);
	return 0;
}