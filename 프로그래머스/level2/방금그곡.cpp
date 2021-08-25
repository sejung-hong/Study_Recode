//���α׷��ӽ� ��� �װ�
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//��� �ð� ���ϱ�
int Play_time(string musicinfo) {
    int start_h = stoi(musicinfo.substr(0, 2));
    int start_m = stoi(musicinfo.substr(3, 2));
    int end_h = stoi(musicinfo.substr(6, 2));
    int end_m = stoi(musicinfo.substr(9, 2));

    return (end_h - start_h) * 60 + end_m - start_m; //end�ð� - start�ð�
}

void Change(string& m) {
    //#�� ������ ��
    while (m.find("#") != string::npos) {
        int i = m.find("#"); //#�� ã��
        string c = "";
        c += (m[i - 1] + 32); 
        m.replace(i - 1, 2, c); // i-1 ��° ���� 2���� c�� ����
    }
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    vector<pair<string, string>> vec;
    for (int i = 0; i < musicinfos.size(); i++) {
        int play_time = Play_time(musicinfos[i]);

        string musicinfo = musicinfos[i].substr(12); //�ð� ���� ����
        string title = musicinfo.substr(0, musicinfo.find(",")); //���� ����
        string info = musicinfo.substr(musicinfo.find(",") + 1); //�Ǻ� ����
        Change(info); //�Ǻ� #�� ����
        string play_music = "";
        int temp = 0;
        //�÷��̵� �ð���ŭ ����� ��ε� ����
        for (int j = 0; j < play_time; j++) {
            play_music += info[temp];
            temp++;
            if (temp == info.size())
                temp = 0;
        }
        vec.push_back(make_pair(play_music, title)); //����� ��ε�, ���� ���� ������ ����
    }

    Change(m); //#�� ����

    int long_music = 0;
    for (int i = 0; i < vec.size(); i++) {
        //������ ��
        if (vec[i].first.find(m) != string::npos) {
            //���� �� �뷡 ����
            if (long_music < vec[i].first.size()) {
                answer = vec[i].second;
                long_music = vec[i].first.size();
            }
        }
    }
    //������ ��ġ���� ������
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