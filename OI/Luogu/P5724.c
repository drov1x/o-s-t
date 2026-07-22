#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main()
{
    int n, mx, mn, a;
    mx = -1000000;
    mn = 1000000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        mx = max(mx, a);
        mn = min(mn, a);
    }
    printf("%d", mx - mn);
    return 0;
}