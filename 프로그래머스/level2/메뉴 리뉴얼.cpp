//���α׷��ӽ� �޴� ������
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if(a.first.size() == b.first.size())
        return a.second > b.second; //���� ������ �������� ����
    return a.first.size() > b.first.size(); //string size ��������
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map <string, int> m;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int i = 0; i < orders.size(); i++) {
        //��Ʈ ����ŷ
        for (int j = 1; j < (1 << orders[i].size()); j++) {
            string menu = "";
            for (int k = 0; k < orders[i].size(); k++) {
                if (j & (1 << k)) {
                    menu += orders[i][k]; //���� ����
                }
            }
            for (int l = 0; l < course.size(); l++) {
                if (course[l] == menu.size()) {
                    m[menu] += 1; // ���� 1����
                    break;
                }
            }
        }
    }

    vector <pair<string, int>> vec(m.begin(), m.end()); //map vector�� copy

    sort(vec.begin(), vec.end(), cmp); //����

    int string_size = 20; //�ִ�
    int string_count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].second == 1) //������ �Ѱ� ���� ��
            continue;
        if (string_size > vec[i].first.size()) { //string �� ���� �ִ� ����
            string_size = vec[i].first.size();
            string_count = vec[i].second;
            answer.push_back(vec[i].first);
            continue;
        }
        if (string_count == vec[i].second) //�ִ� ���� ������ ������
            answer.push_back(vec[i].first);
    }

    sort(answer.begin(), answer.end()); //��� ����
    return answer;
}

int main() {
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2,3,4 };
    solution(orders, course);
    return 0;
}