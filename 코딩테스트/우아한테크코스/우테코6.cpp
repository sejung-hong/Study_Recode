//¿ìÅ×ÄÚ 6
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

double start(string s) {
    string num = "";
    string ampm = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            num += s[i];
        else
            ampm += s[i];
    }
    double time = stod(num);
    
    if (ampm == "PM") {
        if (time >= 6)
            return 0;
        else 
            return 6 - time;
    }
    else {
        if (time <= 9.5)
            return 2.5 + 6;
        else
            return time - 9.5 + 6;
    }


}

double end(string s) {
    string num = "";
    string ampm = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            num += s[i];
        else
            ampm += s[i];
    }
    double time = stod(num);

    if (ampm == "AM")
        return 0;
    else {
        if (time > 6)
            return 5;
        else
            return time - 1.0;
    }
}

string solution(double time, vector<vector<string>> plans) {
    string answer = "";
    map<string, int> result;
    double last = 0;
    for (int i = 0; i < plans.size(); i++) {
        double t = 0;
        t = start(plans[i][1]) + end(plans[i][2]);
        if (t <= time && last <= end(plans[i][2])) {
            last = end(plans[i][2]);
            answer = plans[i][0];
        }
    }
    return answer;
}

int main() {
    double time = 3.5;
    vector<vector<string>> plans = { {"È«Äá", "11PM", "9AM"}, {"¿¤¿¡ÀÌ", "3PM", "2PM"} };
    cout << solution(time, plans) << "\n";
    return 0;
}