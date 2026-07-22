#include <stdio.h>

void print(int i) {
    if (i < 10)
        printf("0%d", i);
    else
        printf("%d", i);
}

int main() {
    int n;
    scanf("%d", &n);
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            print(++k);
        }
        printf("\n");
    }//矩形
    k = 0;
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            print(++k);
        }
        printf("\n");
    }//三角形
    return 0;
}