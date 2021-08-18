//프로그래머스 단어 변환
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

vector<string> words_copy;

//알파벳 하나만 다를때: true, else: false
bool compare(string a, string b) {
    int check = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            check++;
    } //단어 a, b 비교
    if (check == 1)
        return true;
    return false;
}

int BFS(string begin, string target) {
    queue <pair<string, int>> q;
    q.emplace(begin, 0);

    map<string, int> visited;
    visited[begin]++;


    while (!q.empty()) {
        if (q.front().first == target) {
            return q.front().second;
        }//find target
        for (int i = 0; i < words_copy.size(); i++) {
            if (visited[words_copy[i]] == 0) { //방문하지 않은 단어
                if (compare(q.front().first, words_copy[i]) == true) { //단어 변환 가능할 때
                    q.emplace(words_copy[i], q.front().second + 1);//queue push
                    visited[words_copy[i]]++; //방문
                }
            }
        }
        q.pop();
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words_copy = words; //copy 전역변수 변경

    answer = BFS(begin, target);

    return answer;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << solution(begin, target, words);
    return 0;
}