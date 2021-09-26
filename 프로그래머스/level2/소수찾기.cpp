//프로그래머스 소수찾기
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

bool prime(int num) {
    if (num < 2) 
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) 
            return false;
    }
    return true;
}


int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end()); // 오름차순 정렬
    map<int, int> m;
    vector<char> vec;
    for (int i = 0; i < numbers.size(); i++) {
        vec.push_back(numbers[i]);
    }

    do {
        string s = "";
        for (int i = 0; i < vec.size(); i++) {
            s += vec[i];
            if (prime(stoi(s)))
                m[stoi(s)]++;
        }
    } while (next_permutation(vec.begin(), vec.end()));

    for (int i = 1; i < (1 << numbers.size()); i++) {
        vector<char> v;
        for (int j = 0; j < numbers.size(); j++) {
            if (i & (1 << j)) {
                v.push_back(numbers[j]);
            }
        }
        do {
            string s = "";
            for (int k = 0; k < v.size(); k++) {
                s += v[k];
            }
            //cout << s << "\n";
            if (prime(stoi(s)))
                m[stoi(s)]++;
        } while (next_permutation(v.begin(), v.end()));
    }
    answer = m.size();
    return answer;
}

int main() {
    string numbers = "17";
    cout << solution(numbers) << "\n";
    return 0;
}