#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
double compute(char symbol,double op1,double op2);

int main()
{
char post[100],s[100],symbol;
double res,op1,op2;
int top=-1;
printf("Enter postfix expression: ");
scanf("%s",post);
for (int i=0;i<strlen(post);i++)
{
symbol=post[i];
if (isdigit(symbol))
s[++top]=symbol-'0';
else
{
op2=s[top--];
op1=s[top--];
res=compute(symbol,op1,op2);
s[++top]=res;
}
}
res=s[top--];
printf("Result is %f",res);
return 0;
}

double compute(char symbol,double op1,double op2)
{
switch(symbol)
{
case '+':return op1+op2;
case '-':return op1-op2;
case '*':return op1*op2;
case '/':return op1/op2;
case '^':return pow(op1,op2);
case '$':return pow(op1,op2);
}
return 0;
}
