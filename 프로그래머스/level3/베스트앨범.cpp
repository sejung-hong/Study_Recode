//���α׷��ӽ� ����Ʈ�ٹ�
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<string, int> & a, pair<string, int>& b) {
    return a.second > b.second;
} //��������

bool cmp_play(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second; //��������
    }
    return a.first > b.first; //��������
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string,int> m;
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
    }//�ؽ���

    vector<pair<string, int>> v(m.begin(), m.end()); //vector�� copy
    sort(v.begin(), v.end(), cmp); //����

    for (int i = 0; i < v.size(); i++) {
        vector<pair<int, int>> genre;
        for (int j = 0; j < plays.size(); j++) {
            if (v[i].first == genres[j]) {
                genre.push_back(make_pair(plays[j], j));
            }
        }
        sort(genre.begin(), genre.end(), cmp_play); //����

        //�帣�� ���� ���� �ϳ����, �ϳ��� � ����
        answer.push_back(genre[0].second);
        if (genre.size() >= 2) {
            answer.push_back(genre[1].second);
        }
    }
    
    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "classic",  "classic" };
    vector<int> plays = { 500, 1000, 400, 300, 200, 100 };
    solution(genres, plays);


    return 0;
}