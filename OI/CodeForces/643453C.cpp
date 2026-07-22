#include <bits/stdc++.h>
using namespace std;
int main() 
{
    //因为关掉同步超时了，所以就不加快读写了
    int n, m, ans;
    string s;
    char c1,c2,c3,c4,c5;
    cin >> n;
    while (n--)
    {
        cin >> m;
        ans = 0;
        if (m < 3)
        {
            cin >> s;
            s.clear();
            cout << 0 << endl;
            continue;
        }
        c1 = c2 = c3 = c4 = c5 = '\0';
        for (int i = 1; i <= m; i ++)
        {
            scanf("%c", &c5);
            if (c5 < 'a' || c5 > 'z')
            {
                i --;
                continue;
            }
            if ((c3 == 'p') && (c4 == 'i') && (c5 == 'e'))
                ans ++;
            if ((c3 == 'm') && (c4 == 'a') && (c5 == 'p'))
                ans ++;
            if ((c1 == 'm') && (c2 == 'a') && (c3 == 'p') && (c4 == 'i') && (c5 == 'e'))
                ans --;
            //printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5);
            c1 = c2; c2 = c3; c3 = c4; c4 = c5; c5 = '\0';
        }
        cout << ans << endl;
    }
    return 0;   
}     