#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, x, y;
    scanf("%d", &n);
    int mp[n + 2][n + 2];
    x = 1;
    y = (n + 1) / 2;
    memset(mp, 0, sizeof(mp));
    mp[x][y] = 1;
    for (int i = 2; i <= n * n; i ++)
    {
        if (x == 1 && y != n)
        {
            x = n;
            y = y + 1;
        }
        else if (y == n && x != 1)
        {
            x = x - 1;
            y = 1;
        }
        else if (x == 1 && y == n)
        {
            x = x + 1;
        }
        else if (mp[x - 1][y + 1] != 0)
        {
            x = x + 1;
        }else
        {
            x = x - 1;
            y = y + 1;
        }
        mp[x][y] = i;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            printf("%d ", mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}     