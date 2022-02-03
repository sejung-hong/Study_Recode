#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    vector<char> character(8);
    character[0] = 'A'; character[1] = 'C'; character[2] = 'F'; character[3] = 'J';
    character[4] = 'M'; character[5] = 'N'; character[6] = 'R'; character[7] = 'T';
    sort(character.begin(), character.end());

    unordered_map<char, int> um;
    do {
        for (int i = 0; i < 8; i++) {
            um[character[i]] = i;
        }

        bool check = true;
        for (int i = 0; i < data.size(); i++) {
            int interval = abs(um[data[i][0]] - um[data[i][2]]) - 1; //간격
            if (data[i][3] == '=') {
                if (interval != data[i][4] - '0') {
                    check = false;
                    break;
                }
            }
            else if (data[i][3] == '<') {
                if (interval >= data[i][4] - '0') {
                    check = false;
                    break;
                }
            }
            else if (data[i][3] == '>') {
                if (interval <= data[i][4] - '0') {
                    check = false;
                    break;
                }
            }
        }
        if (check == true) {
            answer++;
        }

    } while (next_permutation(character.begin(), character.end()));

    return answer;
}