//���α׷��ӽ� ����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> alpa = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X","Y", "Z" };

    string w = ""; //�����Է�
    string c = ""; //��������
    string w_c = ""; //�����߰�

    for (int i = 0; i < msg.size(); i++) {
        w += msg[i];
        if (i == msg.size() - 1)
            c = ""; //���� ���� ����
        else
            c = msg[i + 1];

        
        auto it = find(alpa.begin(), alpa.end(), w + c);
        //���� �Է�(w)�� ��������(c) ��ģ ���ڰ� ���� ��
        if (it != alpa.end()) {
            if (i == msg.size() - 1) {
                answer.push_back(it - alpa.begin() + 1);
            }
        }
        //���� �Է�(w)�� ��������(c) ��ģ ���ڰ� ���� ��
        else {
            auto it_w = find(alpa.begin(), alpa.end(), w);
            //���� �Է�(w) ã��
            if (it_w != alpa.end()) {
                //cout << it_w - alpa.begin() + 1 << "\n"; //���
                answer.push_back(it_w - alpa.begin() + 1);
                w_c = w + c;
                alpa.push_back(w_c); //���� �߰�
            }
            w = ""; //��ģ���ڰ� ���� �� reset
        }
    }

    return answer;
}

int main() {
    string msg = "ABABABABABABABAB";
    solution(msg);
    return 0;
}