#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int order(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '%' )
        return 3;
    return 0;
}

int op(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')');
}

void intopost(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j = 0;

    for (i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (!op(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        } else {
            while (top >= 0 && order(ch) <= order(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int posteval(char postfix[], int values[]) {
    int stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        if (!op(ch)) {
            int index = ch - 'A';
            stack[++top] = values[index];
        } else {
            int b = stack[top--];
            int a = stack[top--];
            int result;

            switch (ch) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                case '%':
                    result = a % b;
                    break;
            }

            stack[++top] = result;
        }
    }

    return stack[0];
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    int val[7];

    printf("Enter infix: ");
    scanf("%s", infix);

    printf("Enter the values: ");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &val[i]);
    }

    intopost(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int ans = posteval(postfix, val);
    printf("Result: %d\n", ans);

    return 0;
}
