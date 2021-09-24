//프로그래머스 올바른 괄호
#include <iostream>
#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue <int> q;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            q.push(1);
        }
        else {
            if (q.empty())
                return false;
            q.pop();
        }
    }

    if (!q.empty())
        return false;

    return true;
}

int main() {
    string s = "()()";
    cout << solution(s) << "\n";
    return 0;
}