#include <bits/stdc++.h>
using namespace std;

struct Apple
{
    int h, l;
    Apple(int x = 0, int y = 0) : h(x), l(y) {}
};

bool cmp(Apple a, Apple b) 
{
    if (a.l == b.l) 
        return a.h < b.h;
    return a.l < b.l;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    int n, s, a, b, ans = 0;
    cin >> n >> s >> a >> b;
    Apple t[n + 5];
    a += b;
    for (int i = 1; i <= n; i ++)
        cin >> t[i].h >> t[i].l;
    sort(t+1, t+n+1, cmp);
    for (int i = 1; i <= n; i ++)
    {   
        if ((s >= t[i].l) && (a >= t[i].h))
        {
            ans ++;
            s -= t[i].l;
        }
    }
    cout << ans;
    return 0;
}     