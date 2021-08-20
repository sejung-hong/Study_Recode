//���α׷��ӽ� ������
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> tickets_copy;
bool visited[10001] = { false, };
vector<string> answer;
bool check = false;

void DFS(string country, int cnt) {
    answer.push_back(country);
    if (cnt == tickets_copy.size()) {
        check = true;
        return;
    }

    for (int i = 0; i < tickets_copy.size(); i++) {
        if (tickets_copy[i][0] == country && visited[i] == false) {
            visited[i] = true;
            DFS(tickets_copy[i][1], cnt + 1);
            if (check == true)
                return;
            visited[i] = false;
        }
    }
    answer.pop_back();
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end()); //����
    tickets_copy = tickets; //��������

    DFS("ICN", 0); //ICN ����

    return answer;
}

int main() {
    vector<vector<string>> tickets = { {"ICN", "A"},{"ICN", "B"},{"B", "ICN"} };

    solution(tickets);

    return 0;
}