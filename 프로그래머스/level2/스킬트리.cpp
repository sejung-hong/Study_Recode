//프로그래머스 스킬트리
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        int check = true;
        int location = 0;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            int find_location = skill.find(skill_trees[i][j]); //skill에서 찾기
            if (find_location == -1) { //알파벳이 skill에 없을 때
                continue;
            }
            else { //알파벳이 skill에 있을 때
                if (location == find_location) {
                    location++;//다음 스킬
                }
                else{
                    check = false;
                    break;
                }
            }
        }
        if (check == true)
            answer++;
    }

    return answer;
}


int main() {
    string skill = "CBD";
    vector<string> skill_trees = {"CBADF", "AECB", "BDA" };
    cout << solution(skill, skill_trees) << "\n";
    return 0;
}