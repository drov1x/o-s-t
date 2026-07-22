#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    int n, m, b, g, xx, yy, ans = 0;
    cin >> n >> m >> b >> g;
    bool x[n + 2], y[m + 2];
    memset(x, false, sizeof(x));
    memset(y, false, sizeof(y));
    for (int i = 1; i <= b; i ++)
    {
        cin >> xx >> yy;
        for (int j = xx; j <= yy; j ++)
        {
            x[j] = true;
        }
    }
    for (int i = 1; i <= g; i ++)
    {
        cin >> xx >> yy;
        for (int j = xx; j <= yy; j ++)
        {
            y[j] = true;
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (x[i] || y[j]) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}     