#include <stdio.h>

int findTheWinner(int n, int k) {
    int ans = 0;
    for (int i = 2; i <= n; i++)
        ans = (ans + k) % i;
    return ans + 1;
}

int main() {
    printf("%d\n", findTheWinner(5, 2));
    printf("%d\n", findTheWinner(6, 5));
    printf("%d\n", findTheWinner(1, 1));
    return 0;
}