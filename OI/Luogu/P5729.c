#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int w, x, h;
    int q;
    scanf("%d%d%d", &w, &x, &h);
    int a[w + 1][x + 1][h + 1];
    memset(a, 0, sizeof(a));
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x1, y1, z1, x2, y2, z2;
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                for (int l = z1; l <= z2; l++) {
                    a[j][k][l] = 1;
                }
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {
                if (a[i][j][k] == 0) {
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}