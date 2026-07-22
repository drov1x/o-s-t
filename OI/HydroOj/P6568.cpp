#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000006], x, maxn = -1;
#define sum(i) (a[i] - a[i - m])

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i ++)
    {   
        cin >> x;
        a[i] = x + a[i - 1];
    }
    m ++;
    for (int i = m; i <= n; i ++)
    {
        maxn = max(maxn, sum(i));
    }
    cout << maxn;
    return 0;
}