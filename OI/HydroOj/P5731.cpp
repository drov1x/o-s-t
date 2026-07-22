#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n+5][n+5];
    memset(a, 0, sizeof(a));
    int x = 1, y = 1;
    int xx = 0, yy = 1, c = 1;
    for (int i = 1; i <= n * n; i ++)
    {
        a[x][y] = i;
        if ((x == (n - c + 1)) && (y == (n - c + 1)))
        {//右下
            xx = 0, yy = -1;
        }else if ((y == c) &&(x == (n - c + 1)))
        {//左下
            xx = -1, yy = 0;
        }else if ((x == c) && (y == (n - c + 1)))
        {//右上
            xx = 1; yy = 0;
        }else if ((x == c + 1) && (y == c))
        {
            c ++;
            xx = 0, yy = 1;
        }
        x += xx, y += yy;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}