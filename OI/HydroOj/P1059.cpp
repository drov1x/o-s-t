#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n, m;
    cin >> n;
    m = n;
    int a[n+5];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            m --;
            a[i - 1] = -1;
        }
    }
    cout << m << endl;
    for (int j = 0; j < n; j ++)
    {
        if (a[j] != -1)
            cout << a[j] << " ";
    }
    return 0;
}