#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int idx = 0;

bool function(char* expression) {
    if (expression[idx] == '!'){
        idx += 2;
        bool result = function(expression);
        idx++;
        return !result;
    } else if (expression[idx] == '&') {
        idx += 2;
        bool result = true;
        while (expression[idx] != ')') {
            result &= function(expression);
            if (expression[idx] == ',') idx++;
        }
        idx++;
        return result;
    } else if (expression[idx] == '|') {
        idx += 2;
        bool result = false;
        while (expression[idx] != ')') {
            result |= function(expression);
            if (expression[idx] == ',') idx++;
        }
        idx++;
        return result;
    } else if (expression[idx] == 't') {
        idx++;
        return true;
    } else if (expression[idx] == 'f') {
        idx++;
        return false;
    }
    return false;
}

bool parseBoolExpr(char* expression) {
    idx = 0;
    return function(expression);
}

int main() {
    idx = 0; printf("%d\n", parseBoolExpr("!(f)"));
    idx = 0; printf("%d\n", parseBoolExpr("|(f,f,f,t)"));
    idx = 0; printf("%d\n", parseBoolExpr("&(t,f)"));
    idx = 0; printf("%d\n", parseBoolExpr("!(&(f,t))"));
    return 0;
}