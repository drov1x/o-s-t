#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    int n, m, x, y, ans, t;
    bool a[100005] = {0};
    cin >> n;
    for (int o = 1; o <= n; o++) 
    {
        cin >> m;
        ans = 0;
        x = y = 0;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= m; i ++)
        {
            cin >> t;
            if (t) 
            {
                a[i] = 1;
                if (x == 0) x = i;
                y = i;
                ans ++;
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= m; i ++) 
        {
            if (a[i])
                cout << "1 ";
            else
            {
                if (i >= x && i <= y)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
        }
        cout /*<< x << ' ' << y */<< endl;
    }
    return 0;
}     