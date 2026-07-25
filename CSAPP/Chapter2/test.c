#include <stdio.h>

int main(){
    char c[] = "hello", d[]="world";
    c[5] = ',';
    printf("%s\n", c);
    char *pc = &c[0], *pd = &d[0];
    printf("%d\n", *pc);
    printf("%d\n", *pd);
    return 0;
}