//���α׷��ӽ� ���� ���� �� �����ϱ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = *min_element(arr.begin(), arr.end());//���� ���� ��

    arr.erase(find(arr.begin(), arr.end(), min)); //����

    if (arr.size() == 0) //����� 0�� ��
        arr.push_back(-1);
    return arr;
}

int main() {
    vector<int> arr = { 4,3,2,1 };
    solution(arr);
    return 0;
}