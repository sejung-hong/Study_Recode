//프로그래머스 N진수 게임
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string all = "";

    all += '0';
    int s = 1;

    for (int i = 1; i < t * m; i++) {
        if (s == t * m + p)
            break;

        int num = i;
        string temp = "";

        while (num > 0) {
            if (num % n < 10)
                temp += (num % n + 48);
            else
                temp += (num % n + 55);
            num /= n;
        }

        for (int j = temp.size() - 1; j >= 0; j--) {
            all += temp[j];
        }
        s += temp.size();
    }

    for (int i = 0; i < t; i++) {
        answer += all[m * i + p - 1];
    }

    return answer;
}

int main() {
    int n = 16;
    int t = 16;
    int m = 2;
    int p = 2;

    cout << solution(n, t, m, p) << "\n";

    return 0;
}