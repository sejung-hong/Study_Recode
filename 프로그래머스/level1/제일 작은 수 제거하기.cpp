//프로그래머스 제일 작은 수 제거하기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = *min_element(arr.begin(), arr.end());//가장 작은 수

    arr.erase(find(arr.begin(), arr.end(), min)); //제거

    if (arr.size() == 0) //사이즈가 0일 때
        arr.push_back(-1);
    return arr;
}

int main() {
    vector<int> arr = { 4,3,2,1 };
    solution(arr);
    return 0;
}