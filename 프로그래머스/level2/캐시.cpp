//���α׷��ӽ� ĳ��
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //remove ���

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    if (cacheSize == 0)
        return cities.size() * 5;

    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower); //�ҹ��� ��ȯ

        auto it = find(cache.begin(), cache.end(), cities[i]);
        if (it == cache.end()) {
            if (cache.size() == cacheSize) {
                cache.erase(remove(cache.begin(), cache.end(), cache[0]), cache.end()); //���� �� ĳ�� ����
            }
            answer += 5;
        }
        else {
            cache.erase(remove(cache.begin(), cache.end(), cities[i]), cache.end()); //����
            answer++;
        }

        cache.push_back(cities[i]);
    }
    return answer;
}

int main() {
    int cacheSize = 3;
    vector<string> cities = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
    cout << solution(cacheSize, cities) << "\n";
    return 0;
}