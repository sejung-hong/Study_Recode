//���α׷��ӽ� �ܾ� ��ȯ
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

vector<string> words_copy;

//���ĺ� �ϳ��� �ٸ���: true, else: false
bool compare(string a, string b) {
    int check = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            check++;
    } //�ܾ� a, b ��
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
            if (visited[words_copy[i]] == 0) { //�湮���� ���� �ܾ�
                if (compare(q.front().first, words_copy[i]) == true) { //�ܾ� ��ȯ ������ ��
                    q.emplace(words_copy[i], q.front().second + 1);//queue push
                    visited[words_copy[i]]++; //�湮
                }
            }
        }
        q.pop();
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words_copy = words; //copy �������� ����

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