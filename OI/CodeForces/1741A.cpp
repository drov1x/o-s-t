#include <bits/stdc++.h>
using namespace std;

//HydroOJ无法评测，已AC

int main()
{   
    char a[10000], b[10000];
    int na, nb, n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%s %s", a, b);
        na = strlen(a);
        nb = strlen(b);
        if (a[na - 1] > b[nb - 1])
        {
            printf("<\n");
            continue;
        }
        if (a[na - 1] < b[nb - 1])
        {
            printf(">\n");
            continue;
        }
        if (a[na - 1] == b[nb - 1])
        {
            if (na > nb)
            {
                if (a[na - 1] == 'S')
                    printf("<\n");
                else
                    printf(">\n");
                continue;

            }
            if (na < nb)
            {
				if (a[na - 1] == 'S')
                    printf(">\n");
                else
                    printf("<\n");
                continue;
            }
            printf("=\n");
        }
    }
    return 0;
}