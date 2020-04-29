#include <stdio.h>
#include <string.h>
#include <ctype.h>
char input[10];
int i, error;
void E();
void T();
void Eprime();
void Tprime();
void F();
main()
{
    i = 0;
    error = 0;
    printf("Recursive descent parsing for the following grammar\n");
    printf("E->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");
    printf("Enter an arithmetic expression:  ");
    gets(input);
    E();
    if (strlen(input) == i && error == 0)
        printf("\nString is Accepted..!!!\n");
    else
        printf("\nString is Rejected..!!!\n");
}
void E()
{
    T();
    Eprime();
}
void Eprime()
{
    if (input[i] == '+')
    {
        i++;
        T();
        Eprime();
    }
}
void T()
{
    F();
    Tprime();
}
void Tprime()
{
    if (input[i] == '*')
    {
        i++;
        F();
        Tprime();
    }
}
void F()
{
    if (isalnum(input[i]))
        i++;
    else if (input[i] == '(')
    {
        i++;
        E();
        if (input[i] == ')')
            i++;

        else
            error = 1;
    }

    else
        error = 1;
}
