//���α׷��ӽ� 6���� ���� �����ϱ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    int num = 0; //�ڽ� ��ȣ
    int weight = 0; //�ڽ� ������
    vector<int> win; //�̱� ���
    vector<int> win_heavy;
    vector<int> lose; //�� ���
    double rate = 0; //�·�
};

bool cmp(Person& a, Person& b) {
    if (a.rate == b.rate) {
        if (a.win_heavy.size() == b.win_heavy.size()) {
            if (a.weight == b.weight)
                return a.num < b.num; //��ȣ ��
            return a.weight > b.weight; //�ڽ� ������ ��
        }
        return a.win_heavy.size() > b.win_heavy.size(); //�ڽź��� �����԰� ���ſ� ���� ���� ��
    }
    return a.rate > b.rate; //�·� ��
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<Person> people;

    for (int i = 0; i < weights.size(); i++) {
        Person p;
        p.num = i + 1;
        p.weight = weights[i];
        for (int j = 0; j < weights.size(); j++) {
            //�̱� ���
            if (head2head[i][j] == 'W') {
                p.win.push_back(weights[j]);
                if (weights[i] < weights[j])
                    p.win_heavy.push_back(weights[j]);
            }
            //�� ���
            if (head2head[i][j] == 'L')
                p.lose.push_back(weights[j]);
        }
        if(p.win.size() != 0)
            p.rate = (double)p.win.size() / (double)(p.win.size() + p.lose.size()); //�·� ���ϱ�

        people.push_back(p);
    }

    sort(people.begin(), people.end(), cmp); //����

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