//프로그래머스 오픈채팅방
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string in = "님이 들어왔습니다.";
string out = "님이 나갔습니다.";
//in out 문장

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> person; //아이디, 닉네임
    vector<vector<string>> records;
    for (int i = 0; i < record.size(); i++) {
        stringstream stream1(record[i]);
        string move, id, nick;
        stream1 >> move >> id >> nick;

        vector<string> user_vec;
        user_vec.push_back(move);
        user_vec.push_back(id);
        user_vec.push_back(nick);
        records.push_back(user_vec); //행동, 아이디, 닉네임 순으로 벡터에 저장

        if (move == "Enter" || move == "Change") {
            person[id] = nick; //아이디에 해당하는 닉네임
        }
    }

    for (int i = 0; i < records.size(); i++) {
        if (records[i][0] == "Enter") {
            //아이디에 해당하는 닉네임을 찾아 출력
            answer.push_back(person[records[i][1]] + in);
        }
        else if (records[i][0] == "Leave") {
            //아이디에 해당하는 닉네임을 찾아 출력
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