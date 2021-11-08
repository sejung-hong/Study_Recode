//©Левдз4
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int temp = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            temp++;
        else {
            answer.push_back(temp);
            temp = 1;
        }
    }
    if (s[0] == s[s.size() - 1]) {
        if (answer.size() == 0)
            answer.push_back(temp);
        else
            answer[0] += temp;
    }
    else {
        answer.push_back(temp);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    string s = "aaabbaaa";
    solution(s);
    return 0;
}