#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    n = n / 52 + (bool)(n % 52);
    //printf("%d\n", n);
    if ((n - 21) <= 693){
        printf("%d\n1", (n - 21) / 7 + (bool)((n - 21) % 7));
        return 0;
    }
    int k = (n - 700) / 21 + (bool)(n % 21);
    int x;
    for (x = 100; x * 7 + k * 21 >= n; x--)
    {

    }
    x++;
    printf("%d\n%d", x, k);
    return 0;
}