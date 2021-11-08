//우테코 5
#include<iostream>
#include <string>
#include <vector>

using namespace std;

int board[1002][1002] = { 0, };

vector<vector<int>> solution(int rows, int columns) {
    vector<vector<int>> answer;
    int r = 0, c = 0;
    int num = 1;
    int zero = 0;
    while (zero < rows*columns) {
        if (board[r][c] == 0)
            zero++; //0이 없어지는 개수
        //루프에 빠질 때
        if (board[r][c] != 0 && board[r][c] % 2 == num % 2)
            break;
        board[r][c] = num;
        //짝수일 때
        if (num % 2 == 0) {
            r++;
            if (r >= rows)
                r = 0;
        }
        else {
            c++;
            if (c >= columns)
                c = 0;
        }
        num++;

    }

    for (int i = 0; i < rows; i++) {
        vector<int> temp;
        for (int j = 0; j < columns; j++) {
            temp.push_back(board[i][j]);
        }
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    int row = 3;
    int columns = 3;
    solution(row, columns);
    return 0;
}