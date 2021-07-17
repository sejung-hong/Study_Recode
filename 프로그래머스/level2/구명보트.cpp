//프로그래머스
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); //오름차순 정렬
    int big = people.size() - 1;
    int small = 0;

    while (small <= big) {
        if (people[small] + people[big] <= limit) {
            small++;
        }
        big--;
        answer++;
    }

    return answer;
}

int main() {
    vector<int> people = { 70, 80,50 };
    int limit = 100;
    cout << solution(people, limit) << "\n";
    return 0;
}