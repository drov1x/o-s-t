#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAXN 100030

//插入排序
//Luogu P1177 3AC 2TLE

int main()
{
    int a[MAXN];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    int j;
    for (int i = 1; i < n; i ++)
    {
        int KEY = a[i];
        for (j = i - 1; j >= 0; j --)
            if (KEY < a[j])
                a[j + 1] = a[j];
            else
                break;
        a[j + 1] = KEY;
    }
    for (int i = 0; i < n; i ++)
        printf("%d ", a[i]);
    return 0;
}