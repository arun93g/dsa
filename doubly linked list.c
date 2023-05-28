#include<stdio.h>
#include<stdlib.h>

void Insertion(int);
void display();
void fb(int);
void del();

typedef struct node node;

struct node{
    node *pre;
    int data;
    node *next;
};

node *head = NULL;


void Insertion(int val)
{
    node *newnode,*temp;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->pre=NULL;
        head=newnode;
    }

    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->pre=temp;
        newnode->next=NULL;
        temp->next=newnode;

    }
}

void fb(int val)
{
    node *temp,*q;
    if(head==NULL)
    {
        printf("list is empty");
    }
    if(head->data==val)
    {
        temp=head;
        temp=temp->next;
        printf("no previous value , %d",head->data);
        temp=NULL;
    }
    else
    {
        temp=head;
        while(temp->data!=val)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            temp=temp->pre;
            printf("%d , no next value",temp->data);

        }
        else{
        q=temp;
        temp=temp->pre;
        q=q->next;
        printf("%d  ,  %d ",temp->data,q->data);
        temp=NULL;
        q=NULL;
        }
    }

}

void display()
{
    node* temp;
    temp=head;
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp!=NULL&&temp!=head){
                printf("-->");}
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

void del()
{
    int num;
    node *temp=head,*prevnode,*nextnode;
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nenter the data to be deleted: ");
    scanf("%d",&num);
        if(temp->data==num)
        {
            head=temp->next;
            head->pre=NULL;
            temp=NULL;
            //free(head);
            free(temp);
        }
        else
        {
          while(temp->data!=num)
          {
              temp=temp->next;
          }
          if(temp->next!=NULL)
          {
          prevnode=temp->pre;
          nextnode=temp->next;
          prevnode->next=nextnode;
          nextnode->pre=prevnode;
          temp=NULL;
          free(temp);
          }
          else
          {
              prevnode=temp->pre;
              prevnode->next=NULL;
              free(temp);
          }
        }

    }

}


int main()
{
    int choice,val,num;
    printf("\tDOUBLY LINKED LIST");
    while(1)
    {
        //printf("\n-----------------------------------------------\n");
    printf("\n\n1.Insert data\n");
    printf("2.Display\n");
    printf("3.display front and back node\n");
    printf("4.Delete data \n");
    printf("5.Exit\n");
    printf("Enter your choice :");
    scanf("%d",&choice);
    printf("\n");

    switch(choice)
    {
    case 1:
        printf("enter data :");
        scanf("%d",&val);
        Insertion(val);
        break;
    case 2:
        display();
        break;
    case 3:
        printf("\nenter the value: ");
        scanf("%d",&num);
        fb(num);
        break;
    case 4:
        del();
        break;
    case 5:
        return 0;
    default:
        exit(0);
    }
    }

}
