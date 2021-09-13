//프로그래머스 숫자 문자열과 영단어
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string number(string num) {
    if (num == "one")
        return "1";
    else if (num == "two")
        return "2";
    else if (num == "three")
        return "3";
    else if (num == "four")
        return "4";
    else if (num == "five")
        return "5";
    else if (num == "six")
        return "6";
    else if (num == "seven")
        return "7";
    else if (num == "eight")
        return "8";
    else if (num == "nine")
        return "9";
    else if (num == "zero")
        return "0";
    else {
        return "";
    }
}

int solution(string s) {
    int answer = 0;
    string answer_s;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            answer_s += number(temp);
            answer_s += s[i];
            temp = "";
        }
        else {
            temp += s[i];
            if (number(temp) != "") {
                answer_s += number(temp);
                temp = "";
            }
        }
    }

    answer = stoi(answer_s);
    return answer;
}

int main() {
    string s = "one4seveneight";
    cout << solution(s) << "\n";
    return 0;
}