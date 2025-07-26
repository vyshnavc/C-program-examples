#include <stdio.h>
#include <ctype.h>

int evaluateExpression(const char *expr) {
    int stack[100];  
    int top = -1;
    int num = 0;
    char op = '+';  

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

       
        if (!isdigit(ch) && ch != ' ' || expr[i + 1] == '\0') {
            if (op == '+') {
                stack[++top] = num;
            } else if (op == '-') {
                stack[++top] = -num;
            } else if (op == '*') {
                stack[top] = stack[top] * num;
            } else if (op == '/') {
                stack[top] = stack[top] / num;
            }
            op = ch;
            num = 0;
        }
    }

   
    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    return result;
}

int main() {
    const char *expression = "2+3*4-1/2+4";
    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);  // Output: 18
    return 0;
}
