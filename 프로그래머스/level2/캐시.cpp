//프로그래머스 캐시
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //remove 헤더

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    if (cacheSize == 0)
        return cities.size() * 5;

    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower); //소문자 변환

        auto it = find(cache.begin(), cache.end(), cities[i]);
        if (it == cache.end()) {
            if (cache.size() == cacheSize) {
                cache.erase(remove(cache.begin(), cache.end(), cache[0]), cache.end()); //제일 앞 캐시 제거
            }
            answer += 5;
        }
        else {
            cache.erase(remove(cache.begin(), cache.end(), cities[i]), cache.end()); //제거
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