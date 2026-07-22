#include <bits/stdc++.h>
using namespace std;

struct aa
{
    int num, place;
};
bool cmp(aa x, aa y)
{
    return (x.num < y.num);
}

int main()
{   
    int n, m;
    cin >> n;
    aa a[n + 5];
    for (int i = 1; i <= n; i ++)
    {
        a[i].place = i;
        scanf("%d", &a[i].num);
    }
    sort(a + 1, a + n + 1, cmp);
    scanf("%d", &m);
    int z, l, r, mid;
    for (int o = 1; o <= m; o ++)
    {
        scanf("%d", &z);
        l = 0, r = n + 1;
        while (l + 1 < r)
        {
            mid = (l + r) / 2;
            if  (a[mid].num < z)
            {
                l = mid;
            }else{
                r = mid;
            }
        }
        if (a[r].num != z)
        {
            printf("0\n");
        }else{
            printf("%d\n", a[r].place);
        }
    }
    return 0;
}