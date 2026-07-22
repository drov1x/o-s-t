#include <bits/stdc++.h>
using namespace std;
#define ta a[i]%100000
#define aa a%100000
#define bb b%100000
int main()
{
    int l, m, u, v, i;
    cin >> l >> m;
    l++;
    int a[m * 2 + 10];
    memset(a, 0, sizeof(a));
    for (i = 0; i < m; i ++)
    {
        cin >> u >> v;
        a[i * 2] = u;
        a[i * 2 + 1] = v + 100000;
    }
    sort(a, a + m * 2, [](int a, int b){return (aa == bb? a < b: aa < bb);});
    i = 0;
    int z = 0, f = 0;
    while (i < 2 * m)
    {
        l += ta;
        //cout << ta << '+' << endl;
        z = 0; f = 1;
        while(z != f)
        {
            i ++;
            if (a[i] > 99999)
                z ++;
            else
                f ++;
        }
        l -= ta + 1;
        //cout << ta << '-' << endl;
        i++;
    }
    //for (i = 0; i < m * 2; i ++)
    //    cout << a[i] << ' ';
    cout << l;
    return 0;
}