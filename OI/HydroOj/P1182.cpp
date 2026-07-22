#include <bits/stdc++.h>
using namespace std;
//先做的P1281，发现这题就是那题的删减版，改了改扩了个数组就过了

#define sum(st, ed) (s[ed] - s[st - 1])

int m, k, s[500005], p[500005];//s=sum, p=page

bool check(int maxn)
{
    int group = 0;
    
    for (int i = 1; i <= m; ++i)
    {
        group ++;
        if (group >= k + 1)
            return false;
        for (int j = i; j <= m; ++j)
        {
            if (sum(j, j) > maxn)
                return false;
            if (sum(i, j) > maxn)
            {
                i = j - 1;
                break;
            }
            if (j == m)
                i = m;
        }
    }
    return true;
}


void bsearch(int l, int r)
{
    int mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> k;
    if (m <= 0) return 0;
    memset(s, 0, sizeof(s));
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= m; i ++)
    {
        cin >> p[i];
        s[i] = p[i] + s[i - 1];
    }
    bsearch((int)(s[m]/k), s[m]);
    return 0;
}