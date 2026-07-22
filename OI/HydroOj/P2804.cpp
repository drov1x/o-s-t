#include <bits/stdc++.h>
using namespace std;

int n, m, t, s[200006], ans = 0, p[200006];

void sorted(int, int);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    s[0] = t = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> t;
        t -= m;
        s[i] = s[i - 1] + t;
    }
    sorted(0, n);
    cout << ans % 92084931;
    return 0;
}

void sorted(int l, int r)
{
    if (l == r) return ;
    int mid = (l+r)>>1;
    sorted(l, mid);
    sorted(mid + 1, r);
    int cnt = l, i = l, j = mid + 1;
    while ((i <= mid) && (j <= r))
    {
        if (s[i] >= s[j])
        {
            p[cnt++] = s[i++];
        }else
        {
            p[cnt++] = s[j++];
            ans += mid - i + 1;
        }
        ans %= 92084931;
    }
    while (i <= mid) p[cnt++] = s[i++];
    while (j <= r) p[cnt++] = s[j++];
    memcpy(s + l, p + l, (r - l + 1) * sizeof(int));
    return ;
}