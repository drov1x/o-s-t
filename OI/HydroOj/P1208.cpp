#include <bits/stdc++.h>
using namespace std;

struct milk
{
    int n, p;
    milk(int x = 0, int y = 0):n(x), p(y){}
};

bool cmp(milk a, milk b)
{
    if (a.p == b.p)
        return a.n < b.n;
    return a.p < b.p;
}

int main()
{
    int n, m, price = 0;
    milk a[5005];
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        cin >> a[i].p >> a[i].n;
    }
    sort(a+1, a+1+m, cmp);
    int i = 1;
    while (n > 0)
    {
        if (n - a[i].n >= 0)
            price += a[i].p * a[i].n;
        else
            price += a[i].p * n;
        n -= a[i].n;
        i ++;
    }
    cout << price;
    return 0;
}