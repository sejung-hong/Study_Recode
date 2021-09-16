//프로그래머스 직업군 추천하기 위클리 챌린지 4주차
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    
    map <string, int> prefer;
    for (int i = 0; i < languages.size(); i++) {
        prefer[languages[i]] = preference[i];
    } //선호도 

    int max_pre = 0; //최대
    for (int i = 0; i < table.size(); i++) {
        stringstream s(table[i]);
        string job;
        s >> job; //직군
        int pre = 0;
        for (int i = 5; i > 0; i--) {
            string lang;
            s >> lang;
            pre += (i * prefer[lang]); //언어 선호도
        }
        if (max_pre < pre) {
            max_pre = pre;
            answer = job;
        } // 가장 큰 선호도
        else if (max_pre == pre) {
            if (answer > job)
                answer = job;
        } // 같을 때 사전순
    }

    return answer;
}

int main() {
    vector <string> table = { "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" };
    vector <string> languages = { "JAVA", "JAVASCRIPT" };
    vector <int> preference = { 7,5 };
    cout << solution(table, languages, preference) << "\n";
    return 0;
}