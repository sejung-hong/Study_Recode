//프로그래머스 최댓값과 최솟값
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int min = 100000;
    int max = -100000;

    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            int num = stoi(temp);
            if (num < min)
                min = num;
            if (num > max)
                max = num;
            temp = "";
        }
        else {
            temp += s[i];
        }
    }

    int num = stoi(temp);
    if (num < min)
        min = num;
    if (num > max)
        max = num;

    answer += to_string(min);
    answer += ' ';
    answer += to_string(max);

    return answer;
}

int main() {
    string s = "-1 -2 -3 -4";

    solution(s);

    return 0;
}