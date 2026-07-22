#include <bits/stdc++.h>
using namespace std;

//差分算法模板题，总用时在490ms左右
int n, m, mp[1002][1002], c[1002][1002], x, y, xx, yy, maxn = -1;

int sum(int, int);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(mp, 0, sizeof(mp));
    memset(c, 0, sizeof(c));
    while (m--)
    {
        cin >> x >> y >> xx >> yy;
        c[x][y]++;
        c[xx+1][y]--;
        c[x][yy+1]--;
        c[xx+1][yy+1]++;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
            cout << sum(i, j) << ' ';
        cout << endl;
    }
    return 0;
}

int sum(int x, int y)
{
    mp[x][y] = mp[x][y-1] + mp[x-1][y] - mp[x-1][y-1] + c[x][y];
    return mp[x][y];
}




/*
以下是暴力算法，总用时在1000ms+
#include <bits/stdc++.h>
using namespace std;

int n, m, mp[1002][1002], x, y, xx, yy, maxn = -1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(mp, 0, sizeof(mp));
    while (m--)
    {
        cin >> x >> y >> xx >> yy;
        for (int i = x; i <= xx; i ++)
            for (int j = y; j <= yy; j ++)
                mp[i][j] ++;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
            cout << mp[i][j] << ' ';
        cout << endl;
    }
    return 0;
}*/