//프로그래머스 압축
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> alpa = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X","Y", "Z" };

    string w = ""; //현재입력
    string c = ""; //다음글자
    string w_c = ""; //사전추가

    for (int i = 0; i < msg.size(); i++) {
        w += msg[i];
        if (i == msg.size() - 1)
            c = ""; //다음 글자 없음
        else
            c = msg[i + 1];

        
        auto it = find(alpa.begin(), alpa.end(), w + c);
        //현재 입력(w)와 다음글자(c) 합친 글자가 있을 때
        if (it != alpa.end()) {
            if (i == msg.size() - 1) {
                answer.push_back(it - alpa.begin() + 1);
            }
        }
        //현재 입력(w)와 다음글자(c) 합친 글자가 없을 때
        else {
            auto it_w = find(alpa.begin(), alpa.end(), w);
            //현재 입력(w) 찾기
            if (it_w != alpa.end()) {
                //cout << it_w - alpa.begin() + 1 << "\n"; //출력
                answer.push_back(it_w - alpa.begin() + 1);
                w_c = w + c;
                alpa.push_back(w_c); //사전 추가
            }
            w = ""; //합친글자가 없을 때 reset
        }
    }

    return answer;
}

int main() {
    string msg = "ABABABABABABABAB";
    solution(msg);
    return 0;
}