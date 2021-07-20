//프로그래머스 가장 큰 수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//a+b, b+a 중 더 큰 수 return
bool compare(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> numbers_string;
    for (int i = 0; i < numbers.size(); i++) {
        numbers_string.push_back(to_string(numbers[i]));
    }//int->string으로 변경

    sort(numbers_string.begin(), numbers_string.end(), compare);
    //정렬

    if (numbers_string.at(0) == "0")
        return "0";
    //수가 모두 0일 때

    for (int i = 0; i < numbers_string.size(); i++) {
        answer += numbers_string[i];
    }//정렬된 string 더하기

    return answer;
}

int main() {
    vector<int> numbers = { 0, 0, 0, 0 };
    cout << solution(numbers) << "\n";
    return 0;
}