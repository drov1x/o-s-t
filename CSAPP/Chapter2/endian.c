#include <stdio.h>

int main(){
    int x = 0x01234567;
    unsigned char *p = (char *)&x;
    printf("%02x %02x\n", *p, *(p+1));
    //67开头为小端，01开头为大端
    return 0;
}