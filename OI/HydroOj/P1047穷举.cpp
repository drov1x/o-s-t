#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, m, u, v;
    cin >> l >> m;
    bool a[l + 10];
    memset(a, 1, sizeof(a));
    for (int i = 0; i < m; i ++)
    {
        cin >> u >> v;
        fill(a + u, a + v + 1, 0);
    }
    int ans = count(a, a + l + 1, 1);
    cout << ans;
    return 0;
}