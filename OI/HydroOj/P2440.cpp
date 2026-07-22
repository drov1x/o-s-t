#include <bits/stdc++.h>
using namespace std;

int n, k, l[100005];

bool check(int x);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(l, 0, sizeof(l));
    long sum = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
        sum += l[i];
    }
    sort(l + 1, l + n + 1);
    if ((k > sum))
    {
        cout << 0 << "\n";
        return 0;
    }
    int left = 1, right = l[n];
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
            left = mid;
        else
            right = mid;
    }   
    cout << left << '\n';
    return 0;
}

inline bool check(int x)
{
    int cut = 0;
    for (int i = 1; i <= n; i++)
        cut += l[i] / x;
    if (cut < k)
        return false;
    return true;
}