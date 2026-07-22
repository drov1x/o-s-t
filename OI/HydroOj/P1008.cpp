#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a, b, c;
    set<int> t;
    for (int i = 100; i <= 333; i ++)
    {
        t.clear();
        a = i;
        b = 2 * a;
        c = 3 * a;
        t.insert(a % 10);
        t.insert((a % 100) / 10);
        t.insert(a / 100);
        t.insert(b % 10);
        t.insert((b % 100) / 10);
        t.insert(b / 100);
        t.insert(c % 10);
        t.insert((c % 100) / 10);
        t.insert(c / 100);
        if (t.size() == 9 && t.count(0) == 0)
        {
            printf("%d %d %d\n", a, b, c);
        }
    }
    return 0;
}     