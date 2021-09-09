//���α׷��ӽ� �ڹ���� ����
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <sstream>

using namespace std;

//�ð���� 90�� ȸ��
void rotation(vector<vector<int>>& key) {
    vector <vector<int>> key_rotation;
    for (int i = 0; i < key.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < key.size(); j++) {
            temp.push_back(key[key.size() - j - 1][i]);
        }
        key_rotation.push_back(temp);
    }
    key = key_rotation;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    map<string, int> blank; //Lock���� ������ִ� ��ġ
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (lock[i][j] == 0) {
                string s = "";
                s += to_string(i);
                s += " "; //" "�� ����
                s += to_string(j);
                blank[s]++; //�ؽ��� blank ��ġ ����
            }
        }
    }
    
    //lock�� Ȩ�� ������
    if (blank.empty())
        return true;

    for (int k = 0; k < 4; k++) { //90�� ȸ��
        //key�� ����κ� vector�� ������ ����
        vector<pair<int, int>> block;
        for (int i = 0; i < key.size(); i++) {
            for (int j = 0; j < key.size(); j++) {
                if (key[i][j] == 1) {
                    block.push_back(make_pair(i, j));
                }
            }
        }

        //lock Ȩ �κ�
        for (auto m : blank) {
            //key ���� �κ�
            for (int n = 0; n < block.size(); n++) {
                stringstream ss(m.first);
                int col, row;
                ss >> col >> row;
                col = block[n].first - col;
                row = block[n].second - row; 
                //key�� ����κ��� lock�� Ȩ�κ����� �̵�
                int check = 0; //lock�� Ȩ�κ��� ��� ä�������� Ȯ��
                //��� key�� ����κ��� �̵�
                for (int x = 0; x < block.size(); x++) {
                    int col_b = block[x].first - col;
                    int row_b = block[x].second - row;
                    //key�� ���Ⱑ �̵��� ��ġ�� lock�� ��ġ�� �������
                    if (col_b >= lock.size() || row_b >= lock.size() || col_b < 0 || row_b < 0) {
                        continue;
                    }
                    //lock�� Ȩ�κ��� ��
                    if (lock[col_b][row_b] == 0)
                        check++;
                    else
                        break;
                }
                //��ĭ�� ��� ä������ ��
                if (check == blank.size())
                    return true;
            }
        }
        rotation(key); //90�� ȸ��
    }

    return answer;
}

int main() {
    vector<vector<int>> key = { {0,0,0}, {1,0,0}, {0,1,1} };
    vector<vector<int>> lock = { {1,1,1}, {1,1,0}, {1,0,1} };
    cout << solution(key, lock) << "\n";
    return 0;
}