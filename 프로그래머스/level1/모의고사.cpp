//프로그래머스 모의고사
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> s1 = { 1,2,3,4,5 };
    vector<int> s2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> s3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int c1 = 0, c2 = 0, c3 = 0;
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (a == s1.size())
            a = 0;
        if (b == s2.size())
            b = 0;
        if (c == s3.size())
            c = 0;

        if (answers[i] == s1[a]) {
            c1++;
        }
        if (answers[i] == s2[b]) {
            c2++;
        }
        if (answers[i] == s3[c]) {
            c3++;
        }
        a++; 
        b++;
        c++;
    }

    int m = max({ c1, c2, c3 });

    if (c1 == m)
        answer.push_back(1);
    if (c2 == m)
        answer.push_back(2);
    if (c3 == m)
        answer.push_back(3);

    return answer;
}

int main() {
    vector<int> answers = { 1,3,2,4,2 };

    for (int i = 0; i < solution(answers).size(); i++) {
        cout << solution(answers)[i] << "\n";
    }

    return 0;
}