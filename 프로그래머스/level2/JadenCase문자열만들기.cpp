//���α׷��ӽ� JadenCase ���ڿ� �����
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int check = 1;
    for (int i = 0; i < s.size(); i++) {
        if (check == 1) {
            if (islower(s[i])) //�ҹ����϶�
                s[i] = s[i] - 32; //�빮�� ��ȯ
        }
        else {
            if(isupper(s[i])) // �빮���϶�
                s[i] = s[i] + 32; //�ҹ��� ��ȯ
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