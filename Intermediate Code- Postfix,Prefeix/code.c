#define SIZE 400
#include <string.h>
#include <iostream>
#include <conio.h>
#include <ctype.h>
using namespace std;
char s[SIZE];
int top = -1;
void push(char elem)
{
    s[++top] = elem;
}
char pop()
{
    return (s[top--]);
}
int pr(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
    return 0;
}
int main()
{

    char infx[400], pofx[400], ch;
    int i = 0, k = 0;
    cout << "\n\nEnter the Infix Expression ?";
    cin >> infx;
    push('#');
    while ((ch = infx[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            pofx[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
                pofx[k++] = pop();
            top--;
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                pofx[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        pofx[k++] = pop();
    pofx[k] = '\0';
    cout << "Postfix Expression is:" << pofx << endl;
    getch();
    return 0;
}

#define SIZE 50
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
char s[SIZE];
int top = -1;
int s1[SIZE];
int top1 = -1;
void push1(int elem)
{
    s1[++top1] = elem;
}
int pop2()
{
    return (s1[top1--]);
}
void push(char elem)
{
    s[++top] = elem;
}
char pop()
{
    return (s[top--]);
}
int pr(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
    return 0;
}
void prefix(char *infx, char *prfx)
{
    int i = 0, k = 0;
    char ch, elem;
    push('#');
    strrev(infx);
    while ((ch = infx[i++]) != '\0')
    {
        if (ch == ')')
            push(ch);
        else if (isalnum(ch))
            prfx[k++] = ch;
        else if (ch == '(')
        {
            while (s[top] != ')')
                prfx[k++] = pop();
            top--;
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                prfx[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        prfx[k++] = pop();
    prfx[k] = '\0';
    strrev(prfx);
    strrev(infx);
    printf("\n\nPrefix Expression: %s\n", prfx);
}
void caddress(char *prfx)
{
    int i, j = 0, k = 0, l = 0;
    char op1, op2;
    for (i = strlen(prfx) - 1; i >= 0; --i)
        if (prfx[i] != '+' && prfx[i] != '-' && prfx[i] != '*' && prfx[i] != '/' && prfx[i] != '=')
            push(prfx[i]);
        else
        {
            k = 0;
            l = 0;

            ++j;
            op1 = pop();
            op2 = pop();

            if (op1 == '$')
                k = pop2();
            if (op2 == '$')
                l = pop2();
            if (k == 0 && l == 0)
                printf("t%d=%c%c%c \n", j, op1, prfx[i], op2);
            if (k != 0 && l == 0)
                printf("t%d=t%d%c%c \n", j, k, prfx[i], op2);
            if (l != 0 && k == 0)
                printf("t%d=%c%ct%d \n", j, op1, prfx[i], l);
            if (l != 0 && k != 0)
                printf("t%d=t%d%ct%d \n ", j, k, prfx[i], l);

            push('$');
            push1(j);
        }
}
int main()
{
    char infx[50], prfx[50];
    printf("\n\nEnter the Infix Expression ? ");
    scanf("%s", infx);
    prefix(infx, prfx);
    printf("\n3-address code is:\n");
    caddress(prfx);
    return 0;
}
