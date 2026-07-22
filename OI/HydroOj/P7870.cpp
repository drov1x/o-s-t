#include <bits/stdc++.h>
using namespace std;
int main() 
{
    struct pcs
    {
        long long l, r, sum;
    }t;
    long long n, m, x, sum;
    vector<pcs> z;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> m;
        if (m == 1)
        {
            cin >> t.l >> t.r;
            t.sum = t.r - t.l + 1;
            z.push_back(t);
        }else
        {
            cin >> x;
            sum = 0;
            while (x)
            {
                if (x >= z.back().sum)
                {
                    x -= z.back().sum;
                    sum += (z.back().r + z.back().l) * z.back().sum / 2;
                    z.pop_back();
                }else
                {
                    sum += (z.back().r * 2 - x + 1) * x / 2;
                    z.back().r -= x;
                    z.back().sum -= x;
                    x = 0;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}