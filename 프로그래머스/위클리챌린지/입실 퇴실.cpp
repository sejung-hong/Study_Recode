//���α׷��ӽ� 7���� �Խ� ���
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(enter.size() + 1);
    vector<int> inout;

    int leave_i = 0;
    int enter_i = 0;

    while (enter_i != enter.size()) {
        //���
        if (find(inout.begin(), inout.end(), leave[leave_i]) != inout.end()) {
            inout.erase(find(inout.begin(), inout.end(), leave[leave_i])); //���
            leave_i++;
        }
        //�Խ�
        else {
            for (int i = 0; i < inout.size(); i++) {
                answer[inout[i]] += 1; //���� ��� ����
            }
            answer[enter[enter_i]] += inout.size();
            inout.push_back(enter[enter_i]); //�Խ�
            enter_i++;
        }

    }
    //113223

    answer.erase(answer.begin());
    return answer;
}

int main() {
    vector<int> enter = { 1,3,2 };
    vector<int> leave = { 1,2,3 };
    solution(enter, leave);
    return 0;
}