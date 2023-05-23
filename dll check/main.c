#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node * left;
    struct node * right;
};
 typedef struct node * NODE;

 NODE getnode()
 {
     NODE temp;
     temp=(NODE)malloc(sizeof(struct node));
     if(temp==NULL)
     {
         printf("memory cannot be allocated\n");
         return;
     }
     temp->left=temp->right=NULL;
     return temp;
 }

 NODE insbeg(NODE first,int item)
 {
     NODE temp;
     temp=getnode();
     temp->info=item;
     if(first==NULL)
     {
         first=temp;
         return first;
     }
     temp->right=first;
     first->left=temp;
     return temp;
 }
 NODE delspec(NODE first)
 {
     NODE temp,prev,next;
     int item;
     if(first==NULL)
     {
         printf("linked list empty\n");
         return;
     }
     printf("enter the item to be deleted\n");
     scanf("%d",&item);
     if(first->info==item)
     {
         temp=first;
         temp=temp->right;
         first->right=temp->left=NULL;
         free(first);
         return(temp);
     }
     temp=first;
     while(temp->right!=NULL)
     {
         if(temp->info==item)
         {
           next=temp->right;
           temp->left=temp->right=NULL;
           prev->right=next;
           next->left=prev;
           printf("%d deleted\n",temp->info);
           free(temp);
           return first;
         }
         prev=temp;
         temp=temp->right;
     }
    printf("element not found\n");

 }

 void display(NODE first)
 {
     NODE temp;
     temp=first;
     if(first==NULL)
     {
         printf("linked list empty\n");
         return;
     }
     while(temp->right!=NULL)
     {
         printf("%d",temp->info);
         temp=temp->right;
     }
     printf("%d",temp->info);
     return;
 }

 NODE insatpos(NODE first,int item)
 {
     NODE nw,temp,prev,check;
     int pos,count=1,poscnt=0;
     nw=getnode();
     nw->info=item;
     if(first==NULL)
     {
         printf("linked list empty\n");
         return;
     }
     check=first;
     while(check->right!=NULL)
     {
         count=count+1;
         check=check->right;
     }
     printf("enter the position\n");
     scanf("%d",&pos);
     if(pos>count)
     {
         printf("cannot insert at specified position\n");
         return first;
     }
     if(pos==0)
     {
         nw->right=first;
         first->left=nw;
         return nw;
     }
     temp=first;
     while(pos!=poscnt)
     {
         temp=temp->right;
         poscnt=poscnt+1;
     }
     nw->right=temp;
     temp->left=nw;
     first->right=nw;
     nw->left=first;
     return first;
 }


 int main()
{
 int choice,item;
 NODE first=NULL;
 for(;;)
 {
 printf("\nEnter your choice\t1 insbeg\t2 Delspec\t3 Display\t4 insatpos\t5 Exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: printf("Enter the data\n");
 scanf("%d",&item);
 first=insbeg(first,item);
 break;
 case 2: first=delspec(first);
 break;
 case 3:display(first);
 break;
 case 4: printf("Enter the data\n");
 scanf("%d",&item);
 first=insatpos(first,item);
 break;
 case 5:exit(0);
 }
}
 return 0;
}
