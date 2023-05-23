#include<stdio.h>
int prime[100];
void sieve(int n)
{
 for(int i=0; i<=n; ++i) prime[i] = 1; //Initialize prime to 1
 for (int p = 2; p * p <= n; p++)
 if (prime[p])
 for (int j = p * p; j <= n; j += p)
 prime[j] = 0;
}
int main()
{
 int n;
 printf("Enter upper limit: "); scanf("%d", &n);
 sieve(n);
 for (int p = 2; p <= n; p++)
 if (prime[p])
 printf("%d ",p);
}
