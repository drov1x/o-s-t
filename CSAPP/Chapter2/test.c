#include <stdio.h>

int main(){
    int t = 10, *p = &t;
    long long a = (long long)(p);
    printf("%d\n", sizeof(a));

    printf("%ld\n", a);
    printf("%d\n", *(int *)a);
    return 0;
}

/*
int main(){
    char c[] = "hello", d[]="world";
    c[5] = ',';
    printf("%s\n", c);
    char *pc = &c[0], *pd = &d[0];
    printf("%d\n", *pc);
    printf("%d\n", *pd);
    return 0;
}
*/