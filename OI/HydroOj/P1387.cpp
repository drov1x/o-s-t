#include <bits/stdc++.h>
using namespace std;

int n, m, dp[102][102], x, maxn = -1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i ++)
    {   
        for (int j = 1; j <= m; j ++)
        {
            cin >> x;
            if (x != 0)
            {
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                maxn = max(dp[i][j], maxn);
            }else 
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << maxn;
    return 0;
}