//프로그래머스 최고의 집합
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    //집합을 만들수 없을 때
    if (n > s) {
        answer.push_back(-1);
        return answer;
    }
    
    int div = s / n; //몫
    int namuji = s % n; //나머지

    //n에서 나머지 개수 뺀 만큼
    for (int i = 0; i < n - namuji; i++) {
        answer.push_back(div);
    }
    //나머지 개수만큼
    for (int i = 0; i < namuji; i++) {
        answer.push_back(div + 1);
    }

    return answer;
}

int main() {
    int n = 2;
    int s = 9;
    solution(n, s);
    return 0;
}