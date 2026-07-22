#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 直接把指针指向 2^42 这个位置 */
    char *p = (char *)0x40000000000ULL;

    printf("地址 0x40000000000 (2^42 = %llu)：\n", 1ULL << 42);
    printf("尝试写入一个字节...\n");
    fflush(stdout);

    *p = 'A';   /* <- 这里会崩溃 */

    printf("写入成功：%c\n", *p);
    system("pause");
    return 0;
}
