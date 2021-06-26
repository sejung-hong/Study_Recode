#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;

    for (auto name : participant){
        m[name]++;
    }
    for (auto name : completion){
        m[name]--;
    }

    for (auto elem : m)
    {
        if (elem.second > 0){
            answer = elem.first;
            break;
        }
    }
    return answer;
}

int main() {
    vector<string> a = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> b = { "josipa", "filipa", "marina", "nikola" };
    cout << solution(a, b) << endl;
    return 0;
}
