//���α׷��ӽ� ���ϸ� ����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    }
    else {
        return stoi(a[1]) < stoi(b[1]);
    }
}


vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<vector<string>> file_hnt; // head, number, tail, original ��

    for (int i = 0; i < files.size(); i++) {
        vector<string> file;
        string head = "";
        string number = "";
        string tail = "";
        bool check = false;
        int j = 0;
        while (1) {
            if (isdigit(files[i][j])) {
                break;
            }
            else {
                if (islower(files[i][j])) { //�ҹ����϶�
                    head += (files[i][j] - 32); //�빮�ڷ� ��ȯ
                }
                else {
                    head += files[i][j];
                }
                j++;
            }
            //head
        }
        while (1) {
            if (isdigit(files[i][j])) {
                number += files[i][j]; //number
                j++;
            }
            else {
                break;
            }
        }

        for (int k = j; k < files[i].size(); k++) {
            if (islower(files[i][j])) { //�ҹ����϶�
                tail += (files[i][j] - 32); //�빮�ڷ� ��ȯ
            }
            else {
                tail += files[i][j];
            }
        }

        file.push_back(head); // head
        file.push_back(number); //number
        file.push_back(tail); //tail
        file.push_back(files[i]); //origin

        file_hnt.push_back(file);
    }

    stable_sort(file_hnt.begin(), file_hnt.end(), cmp); //���� ����

    for (int i = 0; i < file_hnt.size(); i++){
        answer.push_back(file_hnt[i][3]);
    }

    return answer;
}

int main() {
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    
    solution(files);

    return 0;
}
