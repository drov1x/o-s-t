#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int a, b, p, n, bb;
    long long based = 1, sum = 1, rn;
    vector<int> num;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> p;
    rn = a;
    based = 1;
    n = 0, bb = b;
    while (bb > 0)
    {
        bb /= 2, n ++;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (b & based) sum *= rn;
        based = based << 1;
        rn *= rn;
        rn %= p;
        sum %= p;
    }
    cout << a << '^' << b << " mod " << p << '=' << sum << endl;
    return 0;
}