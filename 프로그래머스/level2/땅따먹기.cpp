//ÇÁ·Î±×·¡¸Ó½º ¶¥µû¸Ô±â
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int solution(vector<vector<int>> land)
{
    int answer = 0;
    int num = 0;

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            num = 0;
            for (int k = 0; k < 4; k++) {
                if (j != k)
                    num = max(num, land[i-1][k]);
            }
            land[i][j] += num;
        }
    }

    for (int i = 0; i < 4; i++) {
        answer = max(answer, land[land.size() - 1][i]);
    }

    return answer;
}

int main() {
    vector<vector<int>> land = { {1,2,3,5},{5,6,7,8}, {4,3,2,1} };
    cout << solution(land) << "\n";
    return 0;
}