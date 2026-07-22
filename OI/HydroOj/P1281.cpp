#include <bits/stdc++.h>
using namespace std;

#define sum(st, ed) (s[ed] - s[st - 1])

int m, k, s[505], p[505];//s=sum, p=page

struct book
{
    int st, ed;
    book(int a = 0, int b = 0) : st(a), ed(b) {}
}bks[505];

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

void reprint(int maxn)
{
    int cnt = k, i = m, j;
    for (j = m; j >= 1; j --)//大
    {
        if (sum(j, i) > maxn)
        {
            bks[cnt--] = book(j + 1, i);
            i = j;
        }
    }
    bks[cnt--] = book(j + 1, i);
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
    reprint(l);
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
    for (int i = 1; i <= k; i ++)
        cout << bks[i].st << " " << bks[i].ed << "\n";
    return 0;
}