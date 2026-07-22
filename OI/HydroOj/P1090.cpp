#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    int n, ans = 0;
    cin >> n;
    int w[n+5];
    memset(w, 0, sizeof(w));
    for (int i = 1; i <= n; i ++)
    {
        cin >> w[i];
    }
    sort(w+1, w+1+n);
    for (int i = 2; i <= n; i ++)
    {
        ans += w[i - 1] + w[i];
        w[i] += w[i-1];
        sort(w + i, w + n + 1);
    }
    cout << ans;
    return 0;
    //这么多排序居然没爆
}     