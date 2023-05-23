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
    temp->link=NULL;
    return(temp);
}

NODE insrer(NODE first,int item)
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
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=nw;
    //nw->link=first;
    return(first);
}

NODE delbeg(NODE first)
{
    NODE temp;
    temp=first;
    temp=temp->link;
    first->link=NULL;
    printf("deleted element id %d",first->info);
    free(first);
    return(temp);
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
    while(temp!=NULL)
    {
        printf("%d",temp->info);
        temp=temp->link;
    }
}

int main()
{
    NODE first=NULL;
    int ch,item;
    for(;;)
    {
        printf("enter the choice\n1.insert\t2.delete\t3.display\t4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the element\n");
            scanf("%d",&item);
            first=insrer(first,item);
            break;
            case 2:first=delbeg(first);
            break;
            case 3:display(first);
            break;
            case 4:exit(0);
        }
    }
    return 0;
}
