#include <stdio.h>
#include <string.h>

int max(int a, int b){
    return a>b?a: b;
}

int longestValidParentheses(char* s) {
    int balance = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++){
        if (s[i] == '(') {
            balance++;
        } else if (s[i] == ')'){
            if (balance <= 0) {
                s[i] = 'K';
            } else {
                balance--;
            }
        }
    }
    balance = 0;
    for (int i = length - 1; i >= 0; i--){
        if (s[i] == ')') {
            balance++;
        } else if (s[i] == '('){
            if (balance <= 0) {
                s[i] = 'K';
            } else {
                balance--;
            }
        }
    }
    int maxs = 0;
    balance = 0;
    for (int i = 0; i < length; i++){
        if (s[i] != 'K'){
            balance++;
        }else{
            maxs = max(maxs, balance);
            balance = 0;
        }
        //printf("%s", s);
    }
    //printf("\n");
    return max(maxs, balance);
}

int main() {
    char s1[] = "(()";
    printf("%d\n", longestValidParentheses(s1));

    char s2[] = ")()())";
    printf("%d\n", longestValidParentheses(s2));

    char s3[] = "";
    printf("%d\n", longestValidParentheses(s3));

    return 0;
}