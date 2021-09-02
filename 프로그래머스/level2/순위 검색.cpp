//���α׷��ӽ� ���� �˻�
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> m;

//��� ���� 
void combination(string p[5]) {
    string s = "";
    for (int i = 0; i < (1 << 4); i++) {
        s = "";
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) //1�϶�
                s += p[j];
            else  //0�϶�
                s += '-';
        }
        m[s].push_back(stoi(p[4])); // int������ ��ȯ�ؼ� push
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    //����ü ����
    for (int i = 0; i < info.size(); i++) {
        stringstream stream(info[i]);
        string person[5];
        stream >> person[0] >> person[1] >> person[2] >> person[3] >> person[4];
        combination(person); //����ã��
    }

    for (auto& score : m) {
        sort(score.second.begin(), score.second.end()); //score ������ ����
    }

    for (int i = 0; i < query.size(); i++) {
        stringstream stream(query[i]);
        string person[5];
        string a;
        stream >> person[0] >> a >> person[1] >> a >> person[2] >> a >> person[3] >> person[4];

        vector<int> vec = m[person[0] + person[1] + person[2] + person[3]]; //find

        if (vec.size() != 0) {
            //ã������ key ������ ���ų� ū ���ڰ� �迭 �� ��°���� ó�� �����ϴ��� ã�� ����
            auto it = lower_bound(vec.begin(), vec.end(), stoi(person[4])); //lower_bound ����Ž�� ���
            answer.push_back(vec.size() - (it - vec.begin()));
        }
        else {
            answer.push_back(0); //�ƹ��͵� ���� ��
        }
    }

    return answer;
}

int main() {
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    solution(info, query);
    return 0;
}