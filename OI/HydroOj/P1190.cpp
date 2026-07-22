#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, x, a[105], ans = 0;
    memset(a, 0, sizeof(a));
    queue<int> q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        q.push(x);
    }
    for (int i = 1; i <= m; i ++)
    {
        a[i] = q.front();
        q.pop();
    }
    n -= m;
    sort(a + 1, a + m + 1);
    while (q.size() && n --)
    {
        ans += a[1];
        for (int i = m; i >= 1; i --)
        {
            a[i] -= a[1];
        }
        a[1] += q.front();
        q.pop();
        sort(a + 1, a + m + 1);
    }
    ans += a[m];
    cout << ans;
    return 0;
}