//프로그래머스 뉴스 클러스터링
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector <string> s1;
    vector <string> s2;

    //str1 집합
    for (int i = 0; i < str1.size() - 1; i++) {
        string s = "";

        //알파벳이 아닐때
        if (!isalpha(str1[i]) || !isalpha(str1[i+1]))
            continue;

        //대문자로 변환
        s += toupper(str1[i]);
        s += toupper(str1[i+1]);
        s1.push_back(s);
    }
    //str2 집합
    for (int i = 0; i < str2.size() - 1; i++) {
        string s = "";

        //알파벳이 아닐때
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1]))
            continue;

        //대문자로 변환
        s += toupper(str2[i]);
        s += toupper(str2[i + 1]);
        s2.push_back(s);
    }


    int sum = s1.size() + s2.size();
    int common = 0;

    if (sum == 0)
        return 65536;

    for (int i = 0; i < s1.size(); i++) {
        auto it = find(s2.begin(), s2.end(), s1[i]);
        //교집합이 있을 때
        if (it != s2.end()) {
            s2.erase(it);
            common++;
        }
    }
    
    answer = (common * 65536) / (sum - common);
    return answer;
}

int main() {
    string str1 = "a-a1+aa2";
    string str2 = "AAAA12";

    cout << solution(str1, str2) << "\n";

    return 0;
}