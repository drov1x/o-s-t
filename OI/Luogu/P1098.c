#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int p1, p2, p3;
    char str[20000], ch[20000];
    scanf("%d%d%d", &p1, &p2, &p3);
    scanf("%s", str);
    int len = strlen(str);
    memset(ch, 0, sizeof(ch));
    char b, e, k;
    int a;
    for (int i = 1; i <= len; i ++)
    {
        if (str[i - 1] == '-' && i > 0 && i < len && (str[i - 2] < str[i]) && 
            ((str[i - 2] >= 'a' && str[i] <= 'z') || (str[i - 2] >= 'A' && str[i] <= 'Z') 
            || (str[i - 2] >= '0' && str[i] <= '9')))
        {
            if (p3 == 2)
            {
                a = -1;
                b = str[i];
                e = str[i - 2];
            }
            else
            {
                a = 1;
                b = str[i - 2];
                e = str[i];
            }
            for (char j = b + a; j != e; j += a)
            {
                if (p1 == 3)
                    k = '*';
                else if (j >= '0' && j <= '9')
                    k = j;
                else if (j >= 'a' && j <= 'z')
                {
                    if (p1 == 2)
                        k = j - 'a' + 'A';
                    else
                        k = j;
                }
                else if (j >= 'A' && j <= 'Z')
                {
                    if (p1 == 2)
                        k = j - 'A' + 'a';
                    else
                        k = j;
                }
                for (int o = 1; o <= p2; o ++)
                    ch[strlen(ch)] = k;
            }
        }else
            ch[strlen(ch)] = str[i - 1];
    }
    printf("%s\n", ch);
    return 0;
}