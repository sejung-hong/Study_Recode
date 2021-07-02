//프로그래머스 같은숫자는싫어
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\n";
    }

    return answer;
}

int main() {
    vector<int> arr = { 1,1,3,3,0,1,1 };

    solution(arr);

    return 0;
}