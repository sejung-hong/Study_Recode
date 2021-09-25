//프로그래머스 JadenCase 문자열 만들기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int check = 1;
    for (int i = 0; i < s.size(); i++) {
        if (check == 1) {
            if (islower(s[i])) //소문자일때
                s[i] = s[i] - 32; //대문자 변환
        }
        else {
            if(isupper(s[i])) // 대문자일때
                s[i] = s[i] + 32; //소문자 변환
        }

        if (isspace(s[i]))  check = 1;
        
        else   check = 0;

    }
    return s;
}

int main() {
    string s = "3people unFollowed me";
    cout << solution(s) << "\n";
    return 0;
}