#include <bits/stdc++.h>
using namespace std;

int n, m, c[5005][5005], xx = -1, yy = -1, x, y, t, maxn = -1;

#define sum(i, j) (c[i][j] + c[i-m][j-m] - c[i-m][j] - c[i][j-m])

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(c, 0, sizeof(c));
    memset(c, 0, sizeof(c));
    cin >> n >> m;
    while (n--)
    {
        cin >> x >> y >> t;
        x++, y++;
        c[x][y] += t;
        xx = max(xx, x), yy = max(yy, y);
    }
    for (int i = 1; i <= 5001; i ++)
    {
        for (int j = 1; j <= 5001; j ++)
        {
            c[i][j] += c[i][j-1];
        }
    }
    for (int i = 1; i <= 5001; i ++)
    {
        for (int j = 1; j <= 5001; j ++)
        {
            c[i][j] += c[i-1][j];
        }
    }   
    for (int i = m; i <= 5001; i ++)
    {
        for (int j = m; j <= 5001; j ++)
        {
            maxn = max(maxn, sum(i, j));
        }
    }
    cout << maxn;
    return 0;
}