#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int time[10] = {0};
    for (int i = n; i <= m; i++) 
    {
        int j = i;
        while (j >= 10)
        {
            time[j % 10]++;
            j /= 10;
        }
        time[j]++;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", time[i]);
    }
    return 0;
}