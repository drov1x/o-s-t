#include <bits/stdc++.h>
using namespace std;

int n, m, mp[1005][1005], c, x, y, maxn = -2100000000;

#define sum(i, j) (mp[i][j] + mp[i-c][j-c] - mp[i-c][j] - mp[i][j-c])

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(mp, 0, sizeof(mp));
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            mp[i][j] += mp[i][j-1];
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            mp[i][j] += mp[i-1][j];
        }
    }   
    for (int i = c; i <= n; i ++)
    {
        for (int j = c; j <= m; j ++)
        {
            if (sum(i, j) > maxn)
            {
                maxn = sum(i, j);
                x = i, y = j;
            }
        }
    }
    cout << x-c+1 << ' ' << y-c+1;
    return 0;
}