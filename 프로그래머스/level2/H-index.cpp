//���α׷��ӽ� H-Index
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end()); //���� 0 1 3 5 6
    for (int h = 1; h <= citations.size(); h++) {
        int h_less = upper_bound(citations.begin(), citations.end(), h - 1) - citations.begin(); //h�� �̸����� �ο�� �� 
        int h_more = citations.size() - h_less; //h�� �̻� �ο�� ��
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