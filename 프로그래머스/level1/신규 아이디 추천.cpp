//프로그래머스 신규 아이디 추천
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    for (int i = 0; i < new_id.size(); i++) {
        //대문자 소문자 변환
        if (isupper(new_id[i])) {
            new_id[i] = new_id[i] + 32;
        }

        if (new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.' && !islower(new_id[i]) && !isdigit(new_id[i]))
            continue;
        temp += new_id[i];
    }

    int count_one = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (i == 0) {
            if (temp[i] == '.') {
                count_one++;
                continue;
            }
        }
        if (temp[i] == '.') {
            count_one++;
            if (count_one > 1)
                continue;
        }
        else
            count_one = 0;

        answer += temp[i];
    }

    if (answer[answer.size() - 1] == '.') {
        answer.pop_back();
    }

    if (answer.size() == 0)
        answer += "aaa";
    else if (answer.size() <= 2) {
        while (answer.size() < 3)
            answer += answer[answer.size() - 1];
    }
    else if (answer.size() >= 15) {
        answer = answer.substr(0, 15);
        if (answer[answer.size() - 1] == '.')
            answer.pop_back();
    }


    return answer;
}

int main() {
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    cout << solution(new_id) << "\n";
    return 0;
}