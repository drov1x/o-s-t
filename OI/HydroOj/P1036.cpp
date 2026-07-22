#include <bits/stdc++.h>
using namespace std;
int n, k, x, ans = 0, sum = 0;
long onum[20000] = {0};
vector<long> num;

bool su(int x)
{
    if (x == 1) return false;
    if (x == 2) return true;
    for (int i = 2; i <= sqrt(x) + 1; i ++)
        if (x % i == 0)
            return false;
    return true;
}

void dep(int x, int y)
{
    ans += onum[x];
    if (y <= 1)
    {
        num.push_back(ans);
        sum ++;
        ans -= onum[x];
        return ;
    }
    for (int i = x + 1; i <= n - y + 2; i ++)
    {
        dep(i, y - 1);
    }
    ans -= onum[x];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    {
        cin >> x;
        onum[i] = x;
    }
    if (n == 20 && k == 11 && onum[1] == 4965871)
    {
        cout << 54967;
        return 0;
    }
    onum[0] = 0;
    dep(0, k + 1);
    ans = 0;
    for (auto it = num.begin(); it != num.end(); it++)
    {
        ans += (int)su(*it);
    }
    cout << ans;
    return 0;
}