//프로그래머스 다리를 지나는 트럭
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge_ing; //다리를 건너는 트럭
    int current_weight = 0;
    int i = 0;

    while (1) {
        answer++; //시간 증가

        if (bridge_ing.size() == bridge_length) {
            current_weight -= bridge_ing.front(); //다리 빠져나감
            bridge_ing.pop();
        }

        //다리를 건널 수 있을 때
        if (current_weight + truck_weights[i] <= weight) {
            //마지막 트럭일 때
            if (i == truck_weights.size() - 1) {
                answer += bridge_length; //마지막 트럭이 빠져나가는 시간
                break;
            }
            bridge_ing.push(truck_weights[i]); //트럭 다리 진입 
            current_weight += truck_weights[i];
            i++;
        }
        else {
            bridge_ing.push(0); //트럭 진입 불가
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