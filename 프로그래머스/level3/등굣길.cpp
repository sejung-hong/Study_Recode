//ÇÁ·Î±×·¡¸Ó½º µî±·±æ
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int visited[101][101] = { 0, };

    for (int i = 0; i < puddles.size(); i++) {
        visited[puddles[i][1]][puddles[i][0]] = -1;
    }

    visited[1][1] = 1; //Áý
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //Áý
            if (i == 1 && j == 1)
                continue;
            //¿õµ¢ÀÌ
            if (visited[i][j] == -1)
                continue;

            //¿ÞÂÊ À§ÂÊ ¸ðµÎ ¿õµ¢ÀÌ ÀÏ¶§
            if (visited[i - 1][j] == -1 && visited[i][j - 1] == -1)
                visited[i][j] = 0; 
            //À§ÂÊ ¿õµ¢ÀÌ ÀÏ¶§ 
            else if (visited[i - 1][j] == -1)
                visited[i][j] = visited[i][j - 1];
            //¿ÞÂÊ ¿õµ¢ÀÌ ÀÏ¶§
            else if (visited[i][j - 1] == -1)
                visited[i][j] = visited[i - 1][j];
            else
                visited[i][j] = (visited[i - 1][j] + visited[i][j - 1])%1000000007;
       }
    }

    return visited[n][m];
}

int main() {
    int m = 4; int n = 3;
    vector<vector<int>> puddles = { {2,2} };
    cout << solution(m, n, puddles) << "\n";
    return 0;
}