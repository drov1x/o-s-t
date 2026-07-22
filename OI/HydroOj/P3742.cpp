#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    char a[n + 10], b[n + 10], c[n + 10];
    cin >> a >> b;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] < b[i])
        {
            cout << -1;
            return 0;
        }
        if (a[i] != b[i])
            c[i] = b[i];
        else 
            c[i] = a[i];
    }
    for (int i = 0; i < n; i++)
        printf("%c", c[i]);
    return 0;
}     