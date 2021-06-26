//프로그래머스 완주하지못한선수 sort
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i])
            return participant[i];
    }

    return participant[participant.size() - 1];
}

int main() {
    vector<string> a = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> b = { "josipa", "filipa", "marina", "nikola" };
    cout << solution(a, b) << endl;
    return 0;
}