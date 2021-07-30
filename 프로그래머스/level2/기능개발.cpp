//프로그래머스 기능 개발
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> day;
    for (int i = 0; i < progresses.size(); i++) {
        int time = 0;
        day.push_back((100 - progresses[i]) / speeds[i]); // 작업 걸리는 날
        if ((100 - progresses[i]) % speeds[i]) //나머지가 있으면 +1
            ++day.back(); //가장 뒤 벡터 +1
    }

    int service = day[0];
    int num = 1;
    for (int i = 1; i < day.size(); i++ ) {
        if (service >= day[i])
            num++;
        else {
            answer.push_back(num);
            service = day[i];
            num = 1;
        }
    }
    answer.push_back(num);

    return answer;
}

int main() {
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1,1,1,1,1,1 };

    solution(progresses, speeds);

    return 0;
}