#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[50];
int top=-1;
void push(char sym)
{
stack[++top]=sym;
}
char pop()
{
return (stack[top--]);
}

int main()
{
    char a[50];
    printf("enter the string");
    gets(a);
    int n=strlen(a);
    int i;
    for(i=0;i<n;i++)
    {
        push(a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(pop()!=a[i])
        {
            printf("not a palindrome");
            exit(0);
        }
    }
    printf("string is a planindrome");
    return 0;
}
