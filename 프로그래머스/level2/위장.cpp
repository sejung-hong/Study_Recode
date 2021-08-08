//프로그래머스 위장
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> kind;
    for (int i = 0; i < clothes.size(); i++) {
        kind[clothes[i][1]]++;
    }

    for (auto it = kind.begin(); it != kind.end(); it++) {
        answer *= (*it).second + 1;
    }

    return answer - 1;
}

int main() {
    vector<vector<string>> clothes = { { "yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"} };
    cout << solution(clothes) << "\n";
    return 0;
}