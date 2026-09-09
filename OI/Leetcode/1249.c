#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* minRemoveToMakeValid(char* s) {
    int balance = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++){
        if (s[i] == '(') {
            balance++;
        } else if (s[i] == ')') {
            if (balance <= 0) {
                s[i] = '\0';
            } else {
                balance--;
            }
        }
    }
    balance = 0;
    for (int i = length - 1; i >= 0; i--){
        if (s[i] == ')') {
            balance++;
        } else if (s[i] == '(') {
            if (balance <= 0) {
                s[i] = '\0';
            } else {
                balance--;
            }
        }
    }
    balance = 0;
    for (int i = 0; i < length; i++){
        if (s[i] != 0){
            s[balance++] = s[i];
        }
    }
    s[balance]='\0';
    return s;
}

int main() {
    char s1[] = "lee(t(c)o)de)";
    char* r1 = minRemoveToMakeValid(s1);
    printf("%s\n", r1);
    free(r1);

    char s2[] = "a)b(c)d";
    char* r2 = minRemoveToMakeValid(s2);
    printf("%s\n", r2);
    free(r2);

    char s3[] = "))((";
    char* r3 = minRemoveToMakeValid(s3);
    printf("%s\n", r3);
    free(r3);

    return 0;
}