#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false);
    int n, avg, ans = 0;
    int sum = 0;
    cin >> n;
    int a[1005];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        sum += a[i];
    }
    avg = sum / n;
    sum = 0;
    int sumb = 0;
    ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        sum += a[i] - avg;
        if (sum != 0)
            ans ++;
    }
    cout << ans;
    return 0;
}