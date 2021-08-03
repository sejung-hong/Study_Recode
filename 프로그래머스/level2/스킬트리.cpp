//���α׷��ӽ� ��ųƮ��
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
            int find_location = skill.find(skill_trees[i][j]); //skill���� ã��
            if (find_location == -1) { //���ĺ��� skill�� ���� ��
                continue;
            }
            else { //���ĺ��� skill�� ���� ��
                if (location == find_location) {
                    location++;//���� ��ų
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