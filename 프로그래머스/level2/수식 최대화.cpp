//���α׷��ӽ� ���� �ִ�ȭ
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //���밪
#include <algorithm>

using namespace std;

vector<vector<string>> operation = { {"*", "+", "-"},{"*", "-", "+"}, {"+", "*", "-"}, {"+", "-", "*"}, {"-", "*", "+"}, {"-", "+", "*"} };

long long solution(string expression) {
    long long answer = 0;

    //vector v�� ���ڿ� ���� push
    vector <string> v; 
    string num = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            num += expression[i];
        }
        else {
            v.push_back(num); //��
;           num = expression[i];
            v.push_back(num); //����
            num = "";
        }
    }
    v.push_back(num); //������ ��

    vector<long long> answer_list;
    for (int i = 0; i < 6; i++) { //���� 6��
        vector <string> vec;
        vec = v;
        for (int j = 0; j < 3; j++) { //���� �켱 ����
            while (find(vec.begin(), vec.end(), operation[i][j]) !=vec.end()) {
                auto it = find(vec.begin(), vec.end(), operation[i][j]);

                //����
                long long n;
                if (operation[i][j] == "*") {
                    n = stoll(vec[it - vec.begin() - 1]) * stoll(vec[it - vec.begin() + 1]);
                }
                else if (operation[i][j] == "+") {
                    n = stoll(vec[it - vec.begin() - 1]) + stoll(vec[it - vec.begin() + 1]);
                }
                else {
                    n = stoll(vec[it - vec.begin() - 1]) - stoll(vec[it - vec.begin() + 1]);
                }
                vec[it - vec.begin() - 1] = to_string(n); //���� 
                vec.erase(it, it + 2); // ���� ����
            }
        }
        answer = max(answer, abs(stoll(vec[0]))); //�ִ밪 ã��
    }

    return answer;
}

int main() {
    string expression = "100-200*300-500+20";
    cout << solution(expression) << "\n";
    return 0;
}