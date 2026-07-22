#include <stdio.h>
#include <stdbool.h>
#define MAX 10000

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int primes[MAX];
    int count = 0;

    for (int num = 2; num < MAX; num++) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes[count++] = num;
        }
    }
    int i;
    for (i = 0; i < MAX; i++){
        ans += primes[i];
        if (ans > n) 
            break;
        printf("%d\n", primes[i]);
    }
    printf("%d", i);
    return 0;
}