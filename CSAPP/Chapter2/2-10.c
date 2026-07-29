#include <stdio.h>

void inplace_swap(int *x, int *y){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void reverse_array(int a[], int cnt){
    int first, last;
    for (first = 0, last = cnt-1; first <= last; first++, last--){
        inplace_swap(&a[first], &a[last]);
    }
}

int main(){
    int k = 2;
    int v[2*k+1];
    for (int i = 0; i < 2*k+1; i++){
        v[i] = i;
    }
    reverse_array(v, 2*k+1);
    for (int i = 0; i < 2*k+1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}