#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(int leave, string day, vector<int> holidays) {
    int answer = -1;
    int week;
    if (day == "MON")
        week = 6;
    else if (day == "TUE")
        week = 5;
    else if (day == "WED")
        week = 4;
    else if (day == "THU")
        week = 3;
    else if (day == "FRI")
        week = 2;
    else if (day == "SAT")
        week = 1;
    else if (day == "SUN")
        week = 0;

    map<int, int> m;
    while (week < 31) {
        if (week > 0)
            m[week] = 1;
        if (week + 1 < 31)
            m[week+1] = 1;
        week += 7;
    }
    for (int i = 0; i < holidays.size(); i++) {
        m[holidays[i]] = 1;
    }

    //순차적으로 최대 기간 구하기
    for (int i = 30; i >= leave; i--) {
        int k = 1;
        while (k + i < 32) {
            int check = 0;
            int count = 0;
            for (int j = k; j < k+i; j++) {
                if (m[j] == 0)
                    count++;
                if (count > leave) {
                    check = 1;
                    break;
                }
            }
            if (check == 0) {
                answer = i;
                return i;
                break;
            }
            k++;
        }
    }

    return answer;
}

int main() {
    int leave = 4;
    string day = "FRI";
    vector<int> holidays = { 6,21,23,27, 28 };
    cout << solution(leave, day, holidays) << "\n";
    return 0;
}