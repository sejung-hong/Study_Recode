//프로그래머스 비밀지도
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        string s;
        int a = 1;
        for (int j = 0; j < n-1; j++) {
            a *= 2;
        }
        for (int j = 0; j < n - 1; j++) {
            if (arr1[i] / a == 1 || arr2[i] / a == 1) {
                if (arr1[i] / a == 1)
                    arr1[i] -= a;
                if (arr2[i] / a == 1)
                    arr2[i] -= a;
                s += "#";
            }
            else {
                s += " ";
            }
            a /= 2;
        }
        if (arr1[i] % 2 == 1 || arr2[i] % 2 == 1) {
            s += "#";
        }
        else {
            s += " ";
        }
        cout << s << "\n";
        answer.push_back(s);
    }


    return answer;
}

int main() {
    int n = 6;
    vector<int> arr1 = { 46, 33, 33 ,22, 31, 50 };
    vector<int> arr2 = { 27 ,56, 19, 14, 14, 10 };

    solution(n, arr1, arr2);

    return 0;
}