#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a[1000005], x;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //sort(a + 1, a + n + 1);
    while (m--)
    {
        cin >> x;
        int l = 1, r = n, m = (l + r) / 2;
        while (l + 1 <= r)
        {
            m = (l + r) / 2;
            if (a[m] < x)
            {
                l = m + 1;
            }
            else
                r = m;
        }
        if (a[l] == x)
            cout << l << ' ';
        else
            cout << -1 << ' ';
    }
    
    return 0;
}