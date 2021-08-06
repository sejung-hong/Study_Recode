#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> ans;

// 최소성 확인
bool possi(int now) {
    for (int i = 0; i < ans.size(); i++) {
        if ((ans[i] & now) == ans[i])// 1101 & 1000 = 1000, ans[i] < now 무조건
            return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    //모든 부분 집합, 비트마스킹
    for (int i = 1; i <= (1 << relation[0].size()); i++) {
        set<string> s;
        for (int j = 0; j < relation.size(); j++) {
            string now = "";
            //각 위치해 있는 값
            for (int k = 0; k < relation[0].size(); k++) {

                if (i & (1 << k))
                    now += relation[j][k];
            }
            s.insert(now);
        }
        
        //set size가 학생들의 수와 같으면 후보키 가능
        if (s.size() == relation.size() && possi(i))
            ans.push_back(i);
    }

    return ans.size();
}

int main() {
    vector<vector<string>> relation = 
    { {"100", "ryan", "music", "2" }, 
        { "200", "apeach", "math", "2" }, 
        { "300", "tube", "computer", "3" }, 
        {"400", "con", "computer", "4"}, 
        { "500", "muzi", "music", "3"}, 
        { "600", "apeach", "music", "2" }};

    cout << solution(relation) << "\n";

    return 0;
}