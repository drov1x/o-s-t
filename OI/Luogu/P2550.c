#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n + 2][7], b[7] = {0};
    memset(a, 0, sizeof(a));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        for (int j = 0; j <= 6; j++)
        {
            for (int k = 0; k <= 6; k++)
            {
                if (a[i][k] == a[0][j])
                {
                    ans ++;
                    break;
                }
            }
        }
        b[--ans]++;
    }
    for (int i = 6; i >= 0; i--)
        printf("%d ", b[i]);
    return 0;
}