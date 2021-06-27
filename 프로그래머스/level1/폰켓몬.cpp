//프로그래머스 폰켓몬
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m;
    
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }

    /*
    if (m.size() < nums.size() / 2) {
        answer = m.size();
    }
    else {
        answer = nums.size() / 2;
    }
    */

    answer = min(m.size(), nums.size() / 2);

    return answer;
}

int main() {
    vector<int> a = { 3,1,2,3 };

    cout << solution(a) << "\n";
    return 0;
}