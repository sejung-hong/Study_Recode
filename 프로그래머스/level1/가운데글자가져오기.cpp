//���α׷��ӽ� ������ڰ�������
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    if (s.size() % 2 == 1) {
        answer = s[s.size() / 2];
    }
    else {
        answer += s[s.size() / 2 - 1];
        answer += s[s.size() / 2];
    }

    return answer;
}

int main() {
    string s = "qwer";

    cout << solution(s) << "\n";

    return 0;
}
