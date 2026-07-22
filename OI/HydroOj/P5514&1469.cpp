#include <bits/stdc++.h>
using namespace std;
int n, x, y;
//两题是等价的
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> y;
    for (int i = 2; i <= n; i ++)
    {
        cin >> x;
        y ^= x;
    }
    cout << y;
    return 0;
}