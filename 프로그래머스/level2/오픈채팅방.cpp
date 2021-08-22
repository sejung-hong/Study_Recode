//���α׷��ӽ� ����ä�ù�
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string in = "���� ���Խ��ϴ�.";
string out = "���� �������ϴ�.";
//in out ����

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> person; //���̵�, �г���
    vector<vector<string>> records;
    for (int i = 0; i < record.size(); i++) {
        stringstream stream1(record[i]);
        string move, id, nick;
        stream1 >> move >> id >> nick;

        vector<string> user_vec;
        user_vec.push_back(move);
        user_vec.push_back(id);
        user_vec.push_back(nick);
        records.push_back(user_vec); //�ൿ, ���̵�, �г��� ������ ���Ϳ� ����

        if (move == "Enter" || move == "Change") {
            person[id] = nick; //���̵� �ش��ϴ� �г���
        }
    }

    for (int i = 0; i < records.size(); i++) {
        if (records[i][0] == "Enter") {
            //���̵� �ش��ϴ� �г����� ã�� ���
            answer.push_back(person[records[i][1]] + in);
        }
        else if (records[i][0] == "Leave") {
            //���̵� �ش��ϴ� �г����� ã�� ���
            answer.push_back(person[records[i][1]] + out);
        }
    }

    return answer;
}

int main() {
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    solution(record);
    return 0;
}