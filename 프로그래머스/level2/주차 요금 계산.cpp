#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>

using namespace std;

int bTime, bFee, uTime, uFee;

int time(string in, string out) {
    int time = 0;
    time = (stoi(out.substr(0, 2)) - stoi(in.substr(0, 2))) * 60 + (stoi(out.substr(3, 2)) - stoi(in.substr(3, 2)));
    cout << "time : " << time << "\n";
    return time;
}

int fee(int t) {
    int num = bFee;
    if (bTime < t) {
        num += (t - bTime) / uTime * uFee;
        if ((t - bTime) % uTime != 0) {
            num += uFee;
        }
    }

    cout << "fee : " << num << "\n";

    return num;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    bTime = fees[0]; bFee = fees[1]; uTime = fees[2]; uFee = fees[3];

    unordered_map<int, string> IN;
    map<int, int> mapTime;
    for (int i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        string t, IO;
        int number;
        ss >> t >> number >> IO;
        if (IO == "IN") {
            IN[number] = t;
        }
        else {
            mapTime[number] += time(IN[number], t);
            IN[number] = "";
        }
    }

    for (auto m : IN) {
        if (m.second != "") {
            mapTime[m.first] += time(IN[m.first], "23:59");
        }
    }

    for (auto m : mapTime) {
        answer.push_back(fee(m.second));
    }


    return answer;
}