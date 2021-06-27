//���α׷��ӽ� - Ű�е崩����
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int last_left = 10;
    int last_right = 12;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) { //Ű�е� 1, 4, 7 L
            answer += 'L';
            last_left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) { //Ű�е� 3, 6, 9 R
            answer += 'R';
            last_right = numbers[i];
        }
        else {
            if (numbers[i] == 0)
                numbers[i] = 11;
            int dis_left = abs((numbers[i] - 1) / 3 - (last_left - 1) / 3) + abs((numbers[i] - 1) % 3 - (last_left - 1) % 3); //���� ���� �̵� �Ÿ�
            int dis_right = abs((numbers[i] - 1) / 3 - (last_right - 1) / 3) + abs((numbers[i] - 1) % 3 - (last_right - 1) % 3); //������ ���� �̵� �Ÿ�

            if (dis_left == dis_right) { // �̵��Ÿ��� ���� ���� ���� ��
                if (hand == "left") {
                    answer += 'L';
                    last_left = numbers[i];
                }
                else {
                    answer += 'R';
                    last_right = numbers[i];
                }
            }
            else if (dis_left > dis_right) { 
                answer += 'R';
                last_right = numbers[i];
            }
            else {
                answer += 'L';
                last_left = numbers[i];
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string b = "right";

    cout << solution(a, b) << "\n";
    

    return 0;
}