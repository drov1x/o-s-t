#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {return a>b;}

int main()
{
    //ios_base::sync_with_stdio(false);
    int n, a[300005];
    long long ans = 0;
    long double maxn = -1, t;
    memset(a, 0, sizeof(a));
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    sort(a+1, a+1+n, cmp);
    for (int i = 1; i <= n; i ++)
    {
        ans += a[i];
        t = (double)((double)ans/i)*ans;
        if (maxn < t)
            maxn = t;
        /*else 
        {
            printf("%.6Lf", maxn);
            return 0;
        }*/
    }
    printf("%.6Lf", maxn);
    return 0;
}