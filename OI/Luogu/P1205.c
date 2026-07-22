#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 15
char c[MAXN][MAXN], d[MAXN][MAXN], mp[MAXN][MAXN];
int n;

bool checked()
{
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
        {
            if (d[i][j] != mp[i][j])
                return false;
        }
    return true;
}

void t90(bool flag)
{
    if (flag)
        memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
        {
            mp[j][n - 1 - i] = c[i][j];
        }
}

void t180(bool flag)
{
    if (flag)
        memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
        {
            mp[n - 1 - i][n - 1 - j] = c[i][j];
        }
}

void t270(bool flag)
{
    if (flag)
        memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
        {
            mp[n - 1 - j][i] = c[i][j];
        }
}

void mirror()
{
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
        {
            mp[i][n - 1 - j] = c[i][j];
        }
    memcpy(c, mp, sizeof(c));
}


int main()
{
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", c[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", d[i]);
    }
    memcpy(mp, c, sizeof(c));
    bool same = false;
    if (checked())
    {
        same = true;
    }
    
    memset(mp, 0, sizeof(mp));
    t90(1);
    if (checked())
    {
        printf("1");
        return 0;
    }
    else
    {
        t180(1);
        if (checked())
        {
            printf("2");
            return 0;
        }
        else
        {  
            t270(1);
            if (checked())
            {
                printf("3");
                return 0;
            }
            else
            {
                mirror();
                if (checked())
                {
                    printf("4");
                    return 0;
                }
                else
                {
                    t90(0);
                    if (checked())
                    {
                        printf("5");
                        return 0;
                    }
                    else
                    {
                        t180(0);
                        if (checked())
                        {
                            printf("5");
                            return 0;
                        }   
                        else
                        {
                            t270(0);
                            if (checked())
                            {
                                printf("5");
                                return 0;
                            }
                            else
                            {
                                if (same)
                                    printf("6");
                                else
                                    printf("7");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}