#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int CharsToMath(char* math){
    int i = 0, ans = 0;
    char nagtive = 0;
    if (math[i] == '-'){
        nagtive = 1;
        i++;
    }
    while (math[i]){
        ans *= 10;
        ans += math[i++] - '0';
    }
    return nagtive ? -ans : ans;
}

int evalRPN(char** tokens, int tokensSize) {
    int tracks[tokensSize];
    int top = -1;
    for (int i = 0; i < tokensSize; i++){
        if (tokens[i][0] == '+'){
            tracks[top - 1] += tracks[top];
            top--;
        }
        else if (tokens[i][0] == '-' && tokens[i][1] == '\0'){
            tracks[top - 1] -= tracks[top];
            top--;
        }
        else if (tokens[i][0] == '*'){
            tracks[top - 1] *= tracks[top];
            top--;
        }
        else if (tokens[i][0] == '/'){
            tracks[top - 1] /= tracks[top];
            top--;
        }
        else{
            tracks[++top] = CharsToMath(tokens[i]);
        }
    }
    return tracks[0];
}

int main() {
    char* tokens1[] = {"2", "1", "+", "3", "*"};
    printf("%d\n", evalRPN(tokens1, 5));

    char* tokens2[] = {"4", "13", "5", "/", "+"};
    printf("%d\n", evalRPN(tokens2, 5));

    char* tokens3[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    printf("%d\n", evalRPN(tokens3, 13));

    return 0;
}