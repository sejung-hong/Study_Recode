//프로그래머스 두개뽑아서더하기
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    map <int, int> m;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            m[numbers[i] + numbers[j]]++;
        }
    }

    for (auto i : m) {
        answer.push_back(i.first);
        //cout << i.first << "\n";
    }

    return answer;
}

int main() {
    vector<int>numbers = { 2,1,3,4,1 };

    solution(numbers);

    return 0;
}