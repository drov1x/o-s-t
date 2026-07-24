#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for (i = 0; i < len; i++){
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

void test1(){//无对应内容，自己测试用
    char a[] = "hello";
    printf("%d\n", sizeof(a));//6
    printf("%.2x", a[5]);//00
    return;
}

void test2(){//对应原书习题2-7

}

int main(){

    return 0;
}