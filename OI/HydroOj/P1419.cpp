#include <bits/stdc++.h>
using namespace std;

int n, s, t, a[100005] = {0};
double c[100005] = {0.0};

bool check(double mid)
{   
    c[0] = 0;
    int q[100005] = {0};
    int l = 1, r = 0;
    for (int i = 1; i <= n; i ++)
    {
        c[i] = (double)a[i] + c[i-1] - mid;  
    }
    for (int i = 1; i <= n; i ++)
    {
        if (i >= s)
        {
            while (l <= r && c[i - s] < c[q[r]])    r --;
            q[++r] = i - s;
        }
        if (l <= r && q[l] < i - t) l++;
        if (l <= r && c[i] - c[q[l]] >= 0) return true;
    }   
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    double l = -10000, r = 10000, mid;
    while (r - l > 1e-5)
    {
        mid = (l+r) / 2;
        if (check(mid))
        {
            l = mid;
        }else
        {
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << l;
    return 0;
}