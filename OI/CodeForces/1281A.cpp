#include <bits/stdc++.h>
using namespace std;

//HydroOJ无法评测，已AC

int main()
{   
    char a[100000], c[6];
    int n;
    cin >> n;
    int len;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", a);
        len = strlen(a);
        memcpy(c, a + len - 2, 2);
        c[2] = '\0';
        if (!strcmp(c, "po"))
            printf("FILIPINO\n");
        else 
        {
            memcpy(c, a + len - 4, 4);
            c[4] = '\0';
            if (!strcmp(c, "desu") || !strcmp(c, "masu"))
                printf("JAPANESE\n");
            else
                printf("KOREAN\n");
        }
    }
    
    return 0;
}