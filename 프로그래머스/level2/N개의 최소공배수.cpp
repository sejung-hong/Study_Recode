//프로그래머스 N개의 최소공배수
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> gcd;
    answer = (arr[0] * arr[1]) / GCD(arr[0], arr[1]);

    for (int i = 2; i < arr.size(); i++) {
        answer = (answer * arr[i]) / GCD(answer, arr[i]);
    }

    return answer;
}

int main() {
    vector<int> arr = { 2,6, 9, 14};

    cout << solution(arr) << "\n";

    return 0;
}