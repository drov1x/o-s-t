#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h[1000006] = {0};
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];
    sort(h + 1, h + 1 + n);
    int i = n, j = i, hight = h[n];
    long long ans = 0;
    while (ans < m)
    {
        j = i;
        while (h[i] == h[j])
        {
            i --;    
        }
        while ((ans < m) && (hight > h[i]))
        {
            ans += n - i; 
            hight --;
        }
    }
    cout << hight << endl;
    return 0;
}