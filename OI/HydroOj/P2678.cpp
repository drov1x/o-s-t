#include <bits/stdc++.h>
using namespace std;

int L, m, n, s[50005];
#define sum(st, ed) s[ed] - s[st]

bool check(int maxn);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> n >> m;
    {
        if (m == 0)
        {
            cout << L;
            return 0;
        }
    }
    int l = 2000000, r = -1;
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        l = min(sum(i-1, i), l);
        r = (i >= m? max(r, sum(i-m, i)):r);
    }
    s[n+1] = L;
    l = min(sum(n, n + 1), l);
    r = max(r, sum(n - m, n));
    int mid;
    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid ;
        }else
        {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}

inline bool check(int minn)
{
    int num = 0;
    for (int i = 0; i <= n; i ++)
    {
        if (num > m)    return false;
        for (int j = i + 1; j <= n + 1; j ++) 
        {   
            if (sum(i, j) >= minn)
            {
                num += j - i - 1;
                i = j - 1;
                break;
            }
        }
    } 
    if (num > m)    return false;
    return true;
}