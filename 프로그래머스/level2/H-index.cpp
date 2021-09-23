//프로그래머스 H-Index
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end()); //정렬 0 1 3 5 6
    for (int h = 1; h <= citations.size(); h++) {
        int h_less = upper_bound(citations.begin(), citations.end(), h - 1) - citations.begin(); //h번 미만으로 인용된 수 
        int h_more = citations.size() - h_less; //h번 이상 인용된 수
        if (h <= h_more) {
            answer = h;
        }
        else
            break;
    }
    return answer;
}

int main() {
    vector<int> citations = { 3,0,6,1,5 };
    cout << solution(citations) << "\n";
    return 0;
}