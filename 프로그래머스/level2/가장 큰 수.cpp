//���α׷��ӽ� ���� ū ��
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//a+b, b+a �� �� ū �� return
bool compare(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> numbers_string;
    for (int i = 0; i < numbers.size(); i++) {
        numbers_string.push_back(to_string(numbers[i]));
    }//int->string���� ����

    sort(numbers_string.begin(), numbers_string.end(), compare);
    //����

    if (numbers_string.at(0) == "0")
        return "0";
    //���� ��� 0�� ��

    for (int i = 0; i < numbers_string.size(); i++) {
        answer += numbers_string[i];
    }//���ĵ� string ���ϱ�

    return answer;
}

int main() {
    vector<int> numbers = { 0, 0, 0, 0 };
    cout << solution(numbers) << "\n";
    return 0;
}