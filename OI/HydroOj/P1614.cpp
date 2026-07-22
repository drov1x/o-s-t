#include <bits/stdc++.h>
#include <ios>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, a[3003], minn = 100000005, sum = 0;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < m; i ++)
    {
        sum += a[i];
    }
    for (int i = m; i <= n; i ++)
    {
        sum += a[i] - a[i - m];
        minn = min(minn, sum);
    }
    cout << minn;
    return 0;
}