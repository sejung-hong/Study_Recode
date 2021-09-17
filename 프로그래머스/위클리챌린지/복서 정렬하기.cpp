//프로그래머스 6주차 복서 정렬하기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    int num = 0; //자신 번호
    int weight = 0; //자신 몸무게
    vector<int> win; //이긴 사람
    vector<int> win_heavy;
    vector<int> lose; //진 사람
    double rate = 0; //승률
};

bool cmp(Person& a, Person& b) {
    if (a.rate == b.rate) {
        if (a.win_heavy.size() == b.win_heavy.size()) {
            if (a.weight == b.weight)
                return a.num < b.num; //번호 순
            return a.weight > b.weight; //자신 몸무게 순
        }
        return a.win_heavy.size() > b.win_heavy.size(); //자신보다 몸무게가 무거운 복서 많은 순
    }
    return a.rate > b.rate; //승률 순
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<Person> people;

    for (int i = 0; i < weights.size(); i++) {
        Person p;
        p.num = i + 1;
        p.weight = weights[i];
        for (int j = 0; j < weights.size(); j++) {
            //이긴 사람
            if (head2head[i][j] == 'W') {
                p.win.push_back(weights[j]);
                if (weights[i] < weights[j])
                    p.win_heavy.push_back(weights[j]);
            }
            //진 사람
            if (head2head[i][j] == 'L')
                p.lose.push_back(weights[j]);
        }
        if(p.win.size() != 0)
            p.rate = (double)p.win.size() / (double)(p.win.size() + p.lose.size()); //승률 구하기

        people.push_back(p);
    }

    sort(people.begin(), people.end(), cmp); //정렬

    for (auto p : people) {
        answer.push_back(p.num);
    }

    return answer;
}

int main() {
    vector<int> weights = { 145,92,86 };
    vector<string> head2head = { "NLW","WNL","LWN" };
    solution(weights, head2head);
    return 0;
}