#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int d, e;
    d = min(a, min(b, c));
    e = max(a, max(b, c));
    int f = gcd(d, e);
    printf("%d/%d", d/f, e/f);
    return 0;
}