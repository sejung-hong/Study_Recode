//프로그래머스 2016년
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    string day[7] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
    int year[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int sum = 0;
    for (int i = 0; i < a - 1; i++) {
        sum += year[i];
    }
    sum += b;
    answer = day[sum % 7];

    return answer;
}

int main() {
    int a = 5;
    int b = 24;

    cout << solution(a, b) << "\n";

    return 0;
}