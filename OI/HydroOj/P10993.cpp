#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n, x;
    bool bo = true;
    cin >> n;
    n *= 37;
    x = n % 10;
    while (n > 0)
    {
        if (n % 10 != x)
        {
            bo = false;
            break;
        }
        n /= 10;
    }
    printf(bo ? "Yes\n" : "No\n");
    return 0;
}