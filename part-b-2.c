//Develop a program to convert infix arithmetic expression to post fix expression

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char infix[50], postfix[50], s[50], ch;
    int top = -1, len, i, j = 0;

    printf("enter infix expression\n");
    scanf("%s", infix);

    len = strlen(infix);
    s[++top] = '#';

    for(i = 0; i < len; i++)
    {
        ch = infix[i];

        if(isalpha(ch) || isdigit(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == '^')
        {
            while(s[top] == '^')
                postfix[j++] = s[top--];
            s[++top] = ch;
        }
        else if(ch == '*' || ch == '/')
        {
            while(s[top] == '^' || s[top] == '*' || s[top] == '/')
                postfix[j++] = s[top--];
            s[++top] = ch;
        }
        else if(ch == '+' || ch == '-')
        {
            while(s[top] == '^' || s[top] == '*' || s[top] == '/' ||
                  s[top] == '+' || s[top] == '-')
                postfix[j++] = s[top--];
            s[++top] = ch;
        }
        else if(ch == '(')
        {
            s[++top] = ch;
        }
        else if(ch == ')')
        {
            while(s[top] != '(')
                postfix[j++] = s[top--];
            top--;
        }
    }

    while(s[top] != '#')
        postfix[j++] = s[top--];

    postfix[j] = '\0';

    printf("postfix expression = %s", postfix);

    return 0;
}
