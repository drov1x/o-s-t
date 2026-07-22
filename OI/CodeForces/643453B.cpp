#include <bits/stdc++.h>
using namespace std;

int a[200005];

void amake(int i, int times) //执行times边操作
{
    
    return;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    int n, m, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (m < 3)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[j];
            }
            cout << "NO" << endl;
            continue;
        }
        memset(a, 0, sizeof(a));
        for (int j = 1; j <= m; j++)
        {
            cin >> a[j];
        }
        for (int j = 2; j <= m - 1; j++)
        {
            c = a[j - 1];
            if (c < 0)
            {
                cout << "NO" << endl;
                goto end;
            }
            a[j] -= 2 * c;
            a[j - 1] -= c;
            a[j + 1] -= c;
            if (a[j + 1] < 0 || a[j] < 0)
            {
                cout << "NO" << endl;
                goto end;
            }
        }
        for (int j = 1; j <= m; j ++)
        {
            if (a[j] != 0)
            {
                cout << "NO" << endl;
                goto end;
            }
        }
        cout << "YES" << endl;
        end:
    }
    return 0;   
}     