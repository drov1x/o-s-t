#include <bits/stdc++.h>
using namespace std;

//作死用BFS写的，理论上DFS更好
const int xx[4] = {1, 0, -1, 0}, yy[4] = {0, -1, 0, 1};
int n, ans = 0;
int mp[1005][1005];
char c;
struct mapp
{
    int x, y;
    mapp(int x = 0, int y = 0):x(x), y(y) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    memset(mp, 0, sizeof(mp));
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            cin >> c;
            if (c == '.')
                mp[i][j] = 0;
            else if (c == '#')
                mp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (mp[i][j] == 1)
            {
                if ((mp[i-1][j] == 0) || (mp[i+1][j] == 0) || (mp[i][j-1] == 0) || (mp[i][j+1] == 0))
                    mp[i][j] = 2;
            }
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (mp[i][j] == 1 || mp[i][j] == 2)
            {
                bool survive = false;
                queue<mapp> q;
                q.push(mapp(i, j));
                
                if (mp[i][j] == 1) survive = true;
                mp[i][j] = 3;
                
                while (!q.empty())
                {
                    mapp curr = q.front();
                    q.pop();
                    int x = curr.x, y = curr.y;
                    
                    for (int k = 0; k < 4; k ++)
                    {
                        int nx = x + xx[k], ny = y + yy[k];
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                        {
                            if (mp[nx][ny] == 1 || mp[nx][ny] == 2)
                            {
                                if (mp[nx][ny] == 1) 
                                    survive = true;
                                
                                mp[nx][ny] = 3;
                                q.push(mapp(nx, ny));
                            }
                        }
                    }
                }
                if (!survive)
                    ans ++;
            }
        }
    }
    
    cout << ans;
    return 0;
}