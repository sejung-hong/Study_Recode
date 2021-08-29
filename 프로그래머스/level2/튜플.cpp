//���α׷��ӽ� Ʃ��
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

//size ������������ ����
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;

    //���� ã��
    string num = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 48 && s[i] <= 57) {
            num += s[i];
        }
        else {
            if (!num.empty())
                m[stoi(num)] ++; // ���� 1 ����
            num = "";
        }

    }

    vector <pair<int, int>> map_v(m.begin(), m.end()); //map vector�� ��ȯ

    sort(map_v.begin(), map_v.end(), cmp); //size ������������ ����

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