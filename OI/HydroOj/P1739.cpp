#include <bits/stdc++.h>
using namespace std;

int main() 
{
    char c;
    int ans = 0;
    scanf("%c", &c);
    if (c == '(')
    {
        ans ++;
    }
    while(c != '@')
    {
        scanf("%c", &c);
        if (c == '(')
        {
            ans ++;
        }
        else if (c == ')')
        {
            ans --;
        }
        if (ans < 0)
        {
            printf("NO\n");
            return 0;
        }
    }
    if (ans == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}     