//���α׷��ӽ� �ҷ� �����
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool visited[8];
set<string> s; //�ߺ� ���� x

void DFS(vector<string>& user_id, vector<string>& banned_id, int index) {
    if (index == banned_id.size()) {
        string st;
        for (int i = 0; i < user_id.size(); i++) {
            //������̵� ����
            if (visited[i] == true)
                st += user_id[i];
        }
        s.insert(st); //�߰�
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        //���� Ž���� ���
        if (visited[i] == true)
            continue;
        //���̵� ���̰� �ٸ� ���
        if (user_id[i].size() != banned_id[index].size())
            continue;
        
        bool check = true;
        for (int j = 0; j < user_id[i].size(); j++) {
            if (banned_id[index][j] == '*') {
                continue;
            }
            //���� ���� ��� false
            if (banned_id[index][j] != user_id[i][j]) {
                check = false;
                break;
            }
        }
        if (check == true) {
            visited[i] = true; //�湮
            DFS(user_id, banned_id, index + 1);
            visited[i] = false; //�湮 x
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    DFS(user_id, banned_id, 0);
    answer = s.size();
    return answer;
}

int main() {
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "abc1**" };
    cout << solution(user_id, banned_id) << "\n";
    return 0;
}