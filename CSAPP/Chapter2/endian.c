#include <stdio.h>

int main(){
    int x = 0x01234567;
    char *p = (char *)&x;
    printf("%02x %02x %02x %02x\n", (char)*p, (char)*(p+1), (char)*(p+2), (char)*(p+3));
    //67开头为小端，01开头为大端
    return 0;
}