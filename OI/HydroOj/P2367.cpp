#include <bits/stdc++.h>
using namespace std;

int n, p, a[5000006], x, y, z, mig = 99999;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i ++)
    {
        cin >> z;
        a[i] += z, a[i+1] -= z;
    }
    while (p--)
    {
        cin >> x >> y >> z;
        a[x] += z, a[y+1] -= z;
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        ans += a[i];
        mig = min(mig, ans);
    }
    cout << mig;
    return 0;
}