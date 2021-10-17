#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> registered_list, string new_id) {
    string answer = "";

    map<string, int> m;
    for (int i = 0; i < registered_list.size(); i++) {
        m[registered_list[i]]++;
    }

    //존재하지 않을 때
    if (m[new_id] == 0)
        return new_id;

    string S = "", N = "";
    int check = 0;
    for (int i = 0; i < new_id.size(); i++) {
        if (islower(new_id[i]))
            S += new_id[i];
        else
            N += new_id[i];
    }

    int n;
    if (N == "")
        n = 1;
    else
        n = stoi(N) + 1;


    while (1) {
        string new_ = S;
        new_ += to_string(n);
        //존재하지 않을 때
        if (m[new_] == 0)
            return new_;
        n++; //증가
    }

    return answer;
}

int main() {
    vector<string> registered_list = { "cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5" };
    string new_id = "cow";
    cout << solution(registered_list, new_id) << "\n";
    return 0;
}