#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node * link;
};

typedef struct node * NODE;

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("memory cannot be allocated\n");
    }
    temp->link=temp;
    return(temp);
}

NODE insbeg(NODE first,int item)
{
    NODE nw,temp;
    nw=getnode();
    nw->info=item;
    if(first==NULL)
    {
        first=nw;
        return(first);
    }
    temp=first;
    nw->link=first;
    while(temp->link!=first)
    {
        temp=temp->link;
    }
    temp->link=nw;
    return(nw);
}

NODE delrer(NODE first)
{
    NODE temp,prev;
    temp=first;
    while(temp->link!=first)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=first;
    temp->link=NULL;
    printf("%d",temp->info);
    free(temp);
    return(first);
}


void display(NODE first)
{
    NODE temp;
    temp=first;
    if(first==NULL)
    {
        printf("list empty\n");
        return;
    }
    while(temp->link!=first)
    {
        printf("%d\ ",temp->info);
        temp=temp->link;
    }
    printf("%d",temp->info);
}

int main()
{
    NODE first=NULL;
    int ch,item;
    for(;;)
    {
        printf("\nenter the choice\n1.insert\t2.delete\t3.display\t4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the element\n");
            scanf("%d",&item);
            first=insbeg(first,item);
            break;
            case 2:first=delrer(first);
            break;
            case 3:display(first);
            break;
            case 4:exit(0);
        }
    }
    return 0;
}
