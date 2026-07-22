#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAX 1035

bool mp[MAX][MAX];

void drew(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            mp[i][j] = false;
}

void catched(int x1, int y1, int x2, int y2)
{
    if ((x2 - x1) < 1 || (y2 - y1) < 1)
        return;
    drew(x1, y1, (x1 + x2 - 1) / 2, (y1 + y2 - 1) / 2);
    catched((x1 + x2 + 1) / 2, y1, x2, (y1 + y2 - 1) / 2); //右上
    catched(x1, (y1 + y2 + 1) / 2, (x1 + x2 - 1) / 2, y2); //左下
    catched((x1 + x2 + 1) / 2, (y1 + y2 + 1) / 2, x2, y2); //右下
}

int main()
{
    memset(mp, 1, sizeof(mp));
    int n;
    scanf("%d", &n);
    catched(1, 1, 1 << (n), 1 << n);
    for (int i = 1; i <= (1 << n); i++)
    {
        for (int j = 1; j <= (1 << n); j++)
            printf(mp[i][j] ? "1 " : "0 ");
        printf("\n");
    }
    return 0;
}