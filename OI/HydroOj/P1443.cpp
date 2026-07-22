#include <bits/stdc++.h>
using namespace std;

const int xx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, yy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

struct place{
    int x, y, step;
};

int main(){
    ios_base::sync_with_stdio(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> mp(n+5, vector<int>(m+5, -1));
    queue<place> bfs;
    bfs.push({x, y, 0});
    mp[x][y] = 0;
    int step;
    while (!bfs.empty()){
        place &now = bfs.front();
        for (int i = 0; i < 8; i ++){
            x = now.x + xx[i];
            y = now.y + yy[i];
            step = now.step + 1;
            if (x > 0 && x <= n && y > 0 && y <= m && (mp[x][y] == -1 || mp[x][y] > step)){
                mp[x][y] = step;
                bfs.push({x, y, step});
            }
        }
        bfs.pop();
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
}