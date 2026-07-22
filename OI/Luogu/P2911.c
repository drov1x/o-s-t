#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int s1, s2, s3;
    int s[100] = {0};
    scanf("%d %d %d", &s1, &s2, &s3);
    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            for (int k = 1; k <= s3; k++)
            {
                s[i + j + k]++;
            }
        }
    }
    int max = 0;
    int g = 1;
    for (int i = 1; i <= s1 + s2 + s3; i++)
    {
        if (s[i] > max)
        {
            max = s[i];
            g = i;
        }
    }
    printf("%d\n", g);
    return 0;
}