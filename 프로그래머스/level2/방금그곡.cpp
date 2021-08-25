//프로그래머스 방금 그곡
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//재생 시간 구하기
int Play_time(string musicinfo) {
    int start_h = stoi(musicinfo.substr(0, 2));
    int start_m = stoi(musicinfo.substr(3, 2));
    int end_h = stoi(musicinfo.substr(6, 2));
    int end_m = stoi(musicinfo.substr(9, 2));

    return (end_h - start_h) * 60 + end_m - start_m; //end시간 - start시간
}

void Change(string& m) {
    //#이 존재할 때
    while (m.find("#") != string::npos) {
        int i = m.find("#"); //#을 찾음
        string c = "";
        c += (m[i - 1] + 32); 
        m.replace(i - 1, 2, c); // i-1 번째 부터 2개를 c로 변경
    }
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    vector<pair<string, string>> vec;
    for (int i = 0; i < musicinfos.size(); i++) {
        int play_time = Play_time(musicinfos[i]);

        string musicinfo = musicinfos[i].substr(12); //시간 제외 정보
        string title = musicinfo.substr(0, musicinfo.find(",")); //음악 제목
        string info = musicinfo.substr(musicinfo.find(",") + 1); //악보 정보
        Change(info); //악보 #음 변경
        string play_music = "";
        int temp = 0;
        //플레이된 시간만큼 재생된 멜로디 저장
        for (int j = 0; j < play_time; j++) {
            play_music += info[temp];
            temp++;
            if (temp == info.size())
                temp = 0;
        }
        vec.push_back(make_pair(play_music, title)); //재생된 멜로디, 음악 제목 순으로 저장
    }

    Change(m); //#음 변경

    int long_music = 0;
    for (int i = 0; i < vec.size(); i++) {
        //존재할 때
        if (vec[i].first.find(m) != string::npos) {
            //가장 긴 노래 길이
            if (long_music < vec[i].first.size()) {
                answer = vec[i].second;
                long_music = vec[i].first.size();
            }
        }
    }
    //조건이 일치하지 않을때
    if (answer == "")
        answer = "(None)";

    return answer;
}

int main() {
    string m = "ABC";
    vector<string> musicinfos = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    cout << solution(m, musicinfos) << "\n";
    return 0;
}