//프로그래머스 전화번호 목록
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const string& a, const string& b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), cmp); //정렬

    map <string, int> m;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = phone_book[0].size(); j <= phone_book[i].size(); j++) {
            if (m[phone_book[i].substr(0, j)] == 1)
                return false;
        }
        m[phone_book[i]]++; //해쉬
    }
    return true;
}

int main() {
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    cout << solution(phone_book) << "\n";
    return 0;
}