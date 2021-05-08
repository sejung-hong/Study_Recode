//카카오 4번
#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string answer = "";

    list <pair<int, string>> kakao;

    kakao.push_back(make_pair(0, "m"));
    kakao.push_back(make_pair(1, "c"));
    kakao.push_back(make_pair(2, "a"));
    kakao.push_back(make_pair(3, "j"));
    kakao.push_back(make_pair(4, "p"));
    kakao.push_back(make_pair(5, "n"));
    kakao.push_back(make_pair(6, "t"));
    kakao.push_back(make_pair(7, "l"));

    auto location = kakao.begin();
    location++;
    location++;
    //처음 위치 어피치
    cout << (*location).second << endl;
    
    pair <int, string> remove;

    /*
    for (auto it = kakao.begin(); it != kakao.end(); it++) {
        cout << (*it).second << endl;
    }//반복자
    */
    string cmd;
    while (1) {
        getline(cin, cmd);
        if (cmd == "")
            break;

        if (cmd[0] == 'U') {
            for (int i = 0; i < cmd[2] - 48; i++) {
                location--;
            }
        }
        else if (cmd[0] == 'D') {
            for (int i = 0; i < cmd[2] - 48; i++) {
                location++;
            }
        }
        else if (cmd[0] == 'C') {
            remove = make_pair((*location).first, (*location).second);
            if (location == kakao.end()) {
                location--;
                kakao.erase(kakao.end());
            }
            else{
                location = kakao.erase(location);
            }
            
        }
        else if (cmd[0] == 'Z'){
            auto add = kakao.begin();
            for (int i = 0; i < remove.first; i++) {
                add++;
            }
            kakao.insert(add, remove);
        }
        cout << (*location).second << endl;
    }
    
    //cout << answer;
    

    return 0;
}
/*
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    return answer;
}
*/