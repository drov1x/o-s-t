#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAXN 100050

//二分排序

int a[MAXN];

void sorts(int *t, int bg, int ed)
{
    if (bg >= ed) 
        return;
    int mid = (bg + ed) / 2;
    sorts(t, bg, mid);
    sorts(t, mid + 1, ed);
    int temp[MAXN];
    int i = bg, j = mid + 1, k = bg;
    while (i <= mid && j <= ed)
    {
        if (t[i] <= t[j])
        {
            temp[k++] = t[i++];
        }
        else
        {
            temp[k++] = t[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = t[i++];
    }
    while (j <= ed)
    {
        temp[k++] = t[j++];
    }
    for (i = bg; i <= ed; i ++)
    {
        t[i] = temp[i];
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
    }
    sorts(a, 0, n - 1);
    for (int i = 0; i < n; i ++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}