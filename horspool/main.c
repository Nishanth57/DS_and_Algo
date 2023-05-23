#include<stdio.h>
#include<time.h>
#include<string.h>
#define MAX 500
int t[MAX];
void shift_table(char b[])
{
 int l2 = strlen(b);
 for(int i=0 ;i<MAX; i++) t[i] = l2;
 for(int j=0; j<l2-1; j++) t[b[j]] = l2-j-1;
}
int horspool(char a[], char b[])
{
 int l1 = strlen(a), l2 = strlen(b);
 int i = l2-1;
 while(i<l1)
 {
 int j=0;
 while(j<l2 && a[i-j] == b[l2-1-j]) j++;
 if(j==l2) return i-l2+1;
 else i += t[a[i]];
 }
 return -1;
}
int main()
{
 char a[20], b[20];
 int l1, l2;
 printf("Enter text: ");
 gets(a);
 printf("Enter pattern: ");
 gets(b);
 l1 = strlen(a);
 l2 = strlen(b);
 shift_table(b);
 int flag = horspool(a,b);
 if(flag==-1) printf("Pattern not found");
 else printf("Found at %d", flag);
}
