//2004 조합 0의 개수
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    long long two = 0;
    long long five = 0;
    for (long long i = 2; i <= n; i *= 2) {
        two = two + n / i;
    }
    for (long long i = 2; i <= n - m; i *= 2) {
        two = two - (n - m) / i;
    }
    for (long long i = 2; i <= m; i *= 2) {
        two = two - m / i;
    }

    for (long long i = 5; i <= n; i *= 5) {
        five = five + n / i;
    }
    for (long long i = 5; i <= n - m; i *= 5) {
        five = five - (n - m) / i;
    }
    for (long long i = 5; i <= m; i *= 5) {
        five = five - m / i;
    }

    if (two > five)
        cout << five;
    else
        cout << two;

    return 0;
}
