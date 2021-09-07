//프로그래머스 이중우선순위큐
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

/*
//벡터 풀이
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector <int> v;

    for (int i = 0; i < operations.size(); i++) {
        stringstream ss(operations[i]);
        int num;
        string s;
        ss >> s >> num;

        if (s == "I") {
            v.push_back(num);
            sort(v.begin(), v.end()); //정렬
        }
        else{
            if (v.empty())
                continue;
            //최댓값 삭제
            if (num == 1) {
                v.pop_back();
            }
            //최솟값 삭제
            else if (num == -1) {
                v.erase(v.begin());
            }
        }
    }

    if (v.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(v[v.size() - 1]); //최댓값
        answer.push_back(v[0]); //최솟값
    }

    return answer;
}
*/

//multiset 풀이
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    for (int i = 0; i < operations.size(); i++) {
        stringstream ss(operations[i]);
        int num;
        string s;
        ss >> s >> num;
        if (s == "I") {
            ms.insert(num);
        }
        else {
            if (ms.empty())
                continue;
            if (num == 1) {
                ms.erase(--ms.end());
            }
            else if (num == -1) {
                ms.erase(ms.begin());
            }
        }
    }

    if (ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--ms.end())); //최댓값
        answer.push_back(*(ms.begin())); //최솟값
    }

    return answer;
}

int main() {
    vector <string> operations = { "I 7","I 5","I -5","D -1" };
    solution(operations);
    return 0;
}