#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m;
    int a[100001] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    int min;
    for (int i = 0; i < m; i ++)
    {
        ans += a[i];
    }
    min = ans;
    for (int i = m; i < n; i++)
    {
        ans += a[i];
        ans -= a[i - m];
        if (ans < min)
        {
            min = ans;
        }
    }
    printf("%d\n", min);
    return 0;
}