//©Левдз 1
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    map<int, int> m;

    int max_size = 0;
    for (int i = 0; i < arr.size(); i++) {
        m[arr[i]]++;
        max_size = max(max_size, m[arr[i]]);
    }

    for (int i = 1; i <= 3; i++) {
        answer.push_back(max_size - m[i]);
    }

    return answer;
}

int main() {
    vector<int> arr = { 2, 1, 3, 1, 2, 1 };
    solution(arr);
    return 0;
}