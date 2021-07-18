//���α׷��ӽ� �ٸ��� ������ Ʈ��
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge_ing; //�ٸ��� �ǳʴ� Ʈ��
    int current_weight = 0;
    int i = 0;

    while (1) {
        answer++; //�ð� ����

        if (bridge_ing.size() == bridge_length) {
            current_weight -= bridge_ing.front(); //�ٸ� ��������
            bridge_ing.pop();
        }

        //�ٸ��� �ǳ� �� ���� ��
        if (current_weight + truck_weights[i] <= weight) {
            //������ Ʈ���� ��
            if (i == truck_weights.size() - 1) {
                answer += bridge_length; //������ Ʈ���� ���������� �ð�
                break;
            }
            bridge_ing.push(truck_weights[i]); //Ʈ�� �ٸ� ���� 
            current_weight += truck_weights[i];
            i++;
        }
        else {
            bridge_ing.push(0); //Ʈ�� ���� �Ұ�
        }
    }

    return answer;
}

int main() {
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7,4,5,6 };
    cout << solution(bridge_length, weight, truck_weights) << "\n";
    return 0;
}