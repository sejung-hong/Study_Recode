//우테코 7
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int line;

vector<string> rotation(vector<string> grid) {
    vector<string> v;
    int num;
    int temp = 0; 
    for (int i = 0; i < line; i++) {
        string s = "";
        num = temp;
        for (int k = line - 1; k > 0; k--) {
            if (num == 0)
                break;
            //한 열에서 두 개 씩 저장
            s += grid[k][num];
            s += grid[k][num - 1];
            num -= 2;
        }
        temp += 2; //증가

        s += grid[line - 1 - i][0]; //마지막 열

        v.push_back(s);
    }
    return v;

}

vector<string> solution(vector<string> grid, bool clockwise) {
    vector<string> answer;
    line = grid.size(); //한 변의 길이

    if (clockwise == true) {
        ///시계방향 한번 회전
        answer = rotation(grid);
    }
    else {
        //시계방향 두번 회전
        answer = rotation(grid);
        answer = rotation(answer);
    }

    return answer;
}

int main() {
    vector<string> grid = { "A","MAN","DRINK","WATER11" };
    bool clockwise = false;
    solution(grid, clockwise);
    return 0;
}
