//¿ìÅ×ÄÚ3
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int solution(vector<string> ings, vector<string> menu, vector<string> sell) {
    int answer = 0;
    map<char, int> ing;
    for (int i = 0; i < ings.size(); i++) {
        char c; int p;
        stringstream stream(ings[i]);
        stream >> c >> p;
        ing[c] = p;
    }

    map<string, int> menu_price;
    for (int i = 0; i < menu.size(); i++) {
        string s1, s2;
        int s3;
        stringstream stream(menu[i]);
        stream >> s1 >> s2 >> s3;
        int price = 0;
        for (int j = 0; j < s2.size(); j++) {
            price += ing[s2[j]];
        }

        menu_price[s1] = s3 - price;
    }

    for (int i = 0; i < sell.size(); i++) {
        string s; int p;
        stringstream stream(sell[i]);
        stream >> s >> p;
        answer += menu_price[s] * p;
    }

    return answer;
}

int main() {
    vector<string> ings = { "r 10", "a 23", "t 124", "k 9" };
    vector<string> menu = { "PIZZA arraak 145", "HAMBURGER tkar 180", "BREAD kkk 30", "ICECREAM rar 50", "SHAVEDICE rar 45", "JUICE rra 55", "WATER a 20" };
    vector<string> sell = { "BREAD 5", "ICECREAM 100", "PIZZA 7", "JUICE 10", "WATER 1" };

    cout << solution(ings, menu, sell) << "\n";

    return 0;
}