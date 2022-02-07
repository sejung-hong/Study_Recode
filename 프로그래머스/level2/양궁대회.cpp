#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> apeachinfo;
vector<int> ryaninfo;
int maxScore = 0;

bool cmp(vector<int> arrow) {
    for (int i = 10; i >= 0; i--) {
        if (arrow[i] == ryaninfo[i]) {
            continue;
        }
        else if (arrow[i] > ryaninfo[i]) {
            return true;
        }
        else {
            return false;
        }
    }
}

void score(vector<int> arrow, int apeachScore, int ryanScore, int n) {
    arrow.push_back(n); //0점 과녁
    if (ryanScore > apeachScore && maxScore <= ryanScore - apeachScore) {
        if (maxScore == ryanScore - apeachScore) {
            if (cmp(arrow) == false) {
                return;
            }
        }
        maxScore = ryanScore - apeachScore;
        ryaninfo = arrow;
    }
    return;
}


void DFS(int pos, vector<int> arrow, int apeachScore, int ryanScore, int n) {
    if (arrow.size() == 10) {
        score(arrow, apeachScore, ryanScore, n);
        return;
    }

    //포함
    if (apeachinfo[pos] < n) {
        arrow.push_back(apeachinfo[pos] + 1);
        DFS(pos + 1, arrow, apeachScore, ryanScore + 10 - pos, n - apeachinfo[pos] - 1);
        arrow.pop_back();
    }
    //미포함
    arrow.push_back(0);
    if (apeachinfo[pos] != 0) {
        DFS(pos + 1, arrow, apeachScore + 10 - pos, ryanScore, n);
    }
    else{
        DFS(pos + 1, arrow, apeachScore, ryanScore, n);
    }
    arrow.pop_back();

    return;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    //copy
    apeachinfo = info;

    vector<int> arrow;
    DFS(0, arrow, 0, 0, n);

    if (maxScore == 0) {
        answer.push_back(-1);
    }
    else {
        answer = ryaninfo;
    }

    return answer;
}

int main() {
    int n = 9;
    vector<int> info = { 0,0,1,2,0,1,1,1,1,1,1 };

    solution(n, info);

    return 0;
}