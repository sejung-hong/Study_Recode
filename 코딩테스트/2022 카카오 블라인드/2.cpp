#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//소수찾기
bool prime(long long num) {
    if (num < 2) return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++) 
        if (num % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    //진수변환
    string s_vers;
    while (n) {
        s_vers += to_string(n % k);
        n /= k;
    }
    string s;   
    for (int i = s_vers.size() - 1; i >= 0; i--) {
        s += s_vers[i];
    }

    //zero 위치 찾기
    vector <int> zero;
    zero.push_back(-1); //가장 앞
    string s_copy = s;
    int location = 0;
    while (s_copy.find("0") != string::npos) {
        int i = s_copy.find("0");
        s_copy = s_copy.substr(i + 1);
        zero.push_back(location + i);
        location += (i + 1);
    }
    zero.push_back(s.size()); //가장 뒤

    for (int i = 0; i < zero.size() - 1; i++) {
        if (zero[i] + 1 == zero[i + 1])
            continue;
        long long num = stoll(s.substr(zero[i] + 1, zero[i + 1] - zero[i] - 1));
        if (prime(num) == true)
            answer++;
    }

    return answer;
}

int main() {
    int n = 110011;
    int k = 10;
    cout << solution(n, k) << "\n";

	return 0;
}