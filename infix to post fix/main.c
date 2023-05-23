  #include <stdio.h>
 #include <stdlib.h>
 #include<string.h>
 int F(char symbol);
 int G(char symbol);

 int main()
 {
 char post[100],s[100],infix[100],symbol;
 int top=-1,j=-1;
 s[++top]='#';
 printf("Enter the infix expression: ");
 scanf("%s",infix);
 for(int i=0;i<strlen(infix);i++)
 {
 symbol=infix[i];
 while(F(s[top])>G(symbol))
 post[++j]=s[top--];
 if(F(s[top])!=G(symbol))
 s[++top]=symbol;
 else
 top--;
 }
 while(s[top]!='#')
 post[++j]=s[top--];
 printf("%s",post);
 return 0;
 }

 int F(char symbol)
 {
 switch(symbol)
 {
 case '+':
 case '-':
 return 2;
 case '*':
 case '/':
 return 4;
 case '^':
 case '$':
 return 5;
 case '(':return 0;
 case ')':
 case '#':
 return -1;
 //default:return 8;
 }


 }

 int G(char symbol)
 {
 switch(symbol)
 {
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 return 3;
 case '^':
 case '$':
 return 6;
 case '(':return 9;
 case ')':
 return 0;
 //default:return 8;
 }
 }
