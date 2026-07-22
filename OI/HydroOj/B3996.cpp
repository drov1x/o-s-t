#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n, m, q, ans, x;
    cin >> n >> m >> q;
    int step[q+5];
    int w = 1;
    ans = n;
    while (ans / 10 > 0)
    {
        ans /= 10;
        w *= 10;
    }
    ans = 0;
    while ((ans < q) && (n != m))
    {
        x = n % 10;
        if (x == 0)
            w /= 10;
        x = (x * x) % 10 * w;
        n = n / 10 + x;
        step[ans] = n;
        ans ++;
    }
    if ((ans >= q) && (n != m))
        cout << -1;
    else
    {
        for (int i = 0; i < ans; i ++)
            printf("%d\n", step[i]);
    }
    return 0;
}