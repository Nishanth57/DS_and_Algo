#include <stdio.h>
#include <stdlib.h>
#define size 5
int front=0,rear=-1;
int count=0;
int q[size];
void insq(int);
int delq();
void display();

int main()
{
    int item,ch,a;
    for(;;)
    {
        printf("\nenter the choice\n1.insert\t2.delete\t3.display\t4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the item\n");
                   scanf("%d",&item);
                   insq(item);
                   break;
            case 2:a=delq();
            printf("%d",a);
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
        }
    }
}
void insq(int item)
{
    if(count==size)
    {
        printf("queue overflow\n");
        return;
    }
    rear=(rear+1)%size;
    q[rear]=item;
    count+=1;
}

int delq()
{
    int item;
    if(count==0)
    {
        printf("queue empty\n");
        return;
    }
    item=q[front];
    front=(front+1)%size;
    count-=1;
    return item;
}

void display()
{
    int i,f=front;
    if(count==0)
    {
        printf("queue empty \n");
    }
    else
    {
    for(i=0;i<count;i++)
    {
        printf("%d",q[f]);
        f=(f+1)%size;
    }
    }
    }
