#include <bits/stdc++.h>
using namespace std;

const int xx[4] = {1, 0, -1, 0}, yy[4] = {0, -1, 0, 1};

struct place{
    int x, y;
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int m, n, minn = 1145141919;
    cin >> m >> n;
    vector<vector<int>> mp(m+5, vector<int>(m+5, -1)), moneys(m+5, vector<int>(m+5, 1145141919));
    while (n --){
        int x, y, color;
        cin >> x >> y >> color;
        mp[x][y] = color;
    }
    queue<place> bfs;
    bfs.push({1, 1});
    int x, y, money;
    moneys[1][1] = 0;
    while (!bfs.empty()){
        place now = bfs.front();
       // cout << now.x << ' ' << now.y << endl;
        if (now.x == m && now.y == m){
            bfs.pop();
            continue;
        }
        for (int i = 0; i < 4; i ++){
            x = now.x + xx[i];
            y = now.y + yy[i];
            money = moneys[now.x][now.y];
            if (x < 1 || x > m || y < 1 || y > m) continue;
            //正常->正常
            if ((mp[now.x][now.y] == 0 || mp[now.x][now.y] == 1) && (mp[x][y] == 0 || mp[x][y] == 1)){
                money += abs(mp[now.x][now.y] - mp[x][y]);
                if(money < moneys[x][y]){
                    bfs.push({x, y});
                    moneys[x][y] = money;
                }
            //不正常->正常
            } else if ((mp[now.x][now.y] == 2 || mp[now.x][now.y] == 3) && (mp[x][y] == 0 || mp[x][y] == 1)){
                money += abs(mp[now.x][now.y] - 2 - mp[x][y]);
                if(money < moneys[x][y]){
                    bfs.push({x, y});
                    moneys[x][y] = money;
                }
            //正常->不正常
            } else if ((mp[now.x][now.y] == 0 || mp[now.x][now.y] == 1) && (mp[x][y] == -1 || mp[x][y] > 1)){
                money += 2;
                if(money < moneys[x][y]){
                    bfs.push({x, y});
                    moneys[x][y] = money;
                    mp[x][y] = mp[now.x][now.y] + 2;
                }
            }
        }
        bfs.pop();
    }
    cout << (moneys[m][m] == 1145141919? -1: moneys[m][m]);
    /*for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            cout << moneys[i][j]<< ' ';
        }
        cout << endl;
    }*/
}