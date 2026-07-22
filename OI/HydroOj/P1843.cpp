#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, t[500005], x, maxn = -1, time = 0;
    memset(t, 0, sizeof(t));
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i ++)
    {
        cin >> x;
        t[x]++;
        maxn = max(maxn, x);
    }
    while (maxn > time * a)
    {
        time ++;
        t[maxn] --;
        t[maxn - b] ++;
        while (!t[maxn])
            maxn --;
    }
    cout << time;
    return 0;
}