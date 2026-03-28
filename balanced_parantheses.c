#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x; // increment top, then insert
}

char pop()
{
    return stack[top--]; // return top element, then decrement
}

int isBalanced(char expr[])
{
    int i = 0;

    while (expr[i] != '\0') // scan until end of string
    {
        if (expr[i] == '(')
        {
            push(expr[i]); // opening bracket so push
        }
        else if (expr[i] == ')')
        {
            if (top == -1)
                return 0; // closing bracket but stack empty → unbalanced

            char topChar = pop(); // pop the top to match

            if (topChar != '(')
                return 0; // mismatched pair → unbalanced
        }

        i++;
    }

    return (top == -1); // if stack empty, all brackets matched
}

int main()
{
    char expr[MAX];

    printf("Enter Expression: ");
    scanf("%s", expr);

    top = -1; 

    if (isBalanced(expr))
        printf("Balanced Expression");
    else
        printf("Unbalanced Expression");

    return 0;
}