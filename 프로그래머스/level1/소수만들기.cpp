//프로그래머스 소수만들기
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool Prime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}//소수구하기

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int n = nums[i] + nums[j] + nums[k];

                if (Prime(n) == true)
                    answer++;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> nums = { 1,2,7,6,4 };
    
    cout << solution(nums) << "\n";

    return 0;
}