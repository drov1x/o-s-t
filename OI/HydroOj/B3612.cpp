#include <bits/stdc++.h>
using namespace std;

//本题是树状数组模板题：给l、r求原数组l、r范围内的和
#define lowbit(x) (x & -x)
int n, m, tree[100005], x, l, r;

int sum(int);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(tree, 0, sizeof(tree));
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> x;
        int j = i;
        while (j <= n)
        {
            tree[j] += x;
            j += lowbit(j);
        }
    }
    cin >> m;
    while (m--)
    {
        cin >> l >> r;
        cout << sum(r) - sum(l - 1) << endl;
    }
    return 0;
}

int sum(int p)
{
    int ans = 0, i = p;
    while (i >= 1)
    {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}