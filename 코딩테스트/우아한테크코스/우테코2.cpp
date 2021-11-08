//우테코
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int study_time(string start, string end) {
    int s_h = stoi(start.substr(0, 2));
    int s_m = stoi(start.substr(3, 2));
    int e_h = stoi(end.substr(0, 2));
    int e_m = stoi(end.substr(3, 2));

    return (e_h - s_h) * 60 + e_m - s_m; //end시간 - start시간
}

string hm(int time) {
    string s = "";
    if (time / 60 < 10)
        s += "0";
    s += to_string(time / 60);
    s += ":";
    s += to_string(time % 60);

    return s;
}

string solution(vector<string> log) {
    string answer = "";

    int real_time = 0;
    for (int i = 0; i < log.size(); i+=2) {
        int time = study_time(log[i], log[i + 1]);
        //1시간 45분 이상
        if (time > 105)
            real_time += 105;
        else if (time >= 5) {
            real_time += time;
        }
    }

    answer = hm(real_time);

    return answer;
}

int main() {
    vector<string> log = { "08:30", "09:00", "14:00", "16:00", "16:01", "16:06", "16:07", "16:11" };
    cout << solution(log) << "\n";
    return 0;
}