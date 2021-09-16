//���α׷��ӽ� ������ ��õ�ϱ� ��Ŭ�� ç���� 4����
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
    } //��ȣ�� 

    int max_pre = 0; //�ִ�
    for (int i = 0; i < table.size(); i++) {
        stringstream s(table[i]);
        string job;
        s >> job; //����
        int pre = 0;
        for (int i = 5; i > 0; i--) {
            string lang;
            s >> lang;
            pre += (i * prefer[lang]); //��� ��ȣ��
        }
        if (max_pre < pre) {
            max_pre = pre;
            answer = job;
        } // ���� ū ��ȣ��
        else if (max_pre == pre) {
            if (answer > job)
                answer = job;
        } // ���� �� ������
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