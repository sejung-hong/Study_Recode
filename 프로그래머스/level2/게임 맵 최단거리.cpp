#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;

int nexti[4] = { 1,0,-1,0 }, nextj[4] = { 0,1,0,-1 };
int n, m;
bool visited[101][101] = { false, };
int maxSize = 0;
vector<vector<int> > map;

struct pos {
    int i;
    int j;
    int dis;
};

int BFS() {
    queue<pos> q;
    q.push({ 0,0,1 });
    visited[0][0] = true;

    while (!q.empty()) {
        pos p = q.front();
        q.pop();
        if (p.i == n - 1 && p.j == m - 1) {
            cout << p.dis << "\n";
            return p.dis;
        }
        for (int k = 0; k < 4; k++) {
            int ni = p.i + nexti[k];
            int nj = p.j + nextj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                continue;
            }
            if (visited[ni][nj] == false && map[ni][nj] == 1) {
                q.push({ ni,nj, p.dis + 1 });
                visited[ni][nj] = true;
            }
        }
    }
    return -1;
}


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    map = maps;
    answer = BFS();

    return answer;
}