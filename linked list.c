#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

void insert();
void display();
void deletion();
void length();

struct node {
    int data;
    struct node *next;
};

node *head=NULL;

int main()
{
    int choice;
    printf("\tLINKED LIST IMPLEMENTATION\n");

    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Length\n5.Exit");
        printf("\nEnter your  choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            deletion();
            break;
        case 4:
            length();
            break;
        case 5:
            goto end;
        default:printf("enter correct choice");
        break;
        }


    }

    end:
        printf("Exited successfully");
}

void insert()
{
    node *temp;
    int value;
    node* newNode=(node*)malloc(sizeof(node));
    printf("enter the data to be inserted: ");
    scanf("%d",&value);

   if(newNode==NULL)
   {
       printf("out of memory");
       return;
   }
   temp=head;
   newNode->data=value;
   if(head==NULL){
        head=newNode;
   newNode->next=NULL;
   }
   else
   {
       while(temp->next!=NULL)
       {
       temp=temp->next;

       }
       temp->next=newNode;
       newNode->next=NULL;
   }
}

void deletion()
{
    display();
    node* temp,*prv;
    temp=head;
    int num;
    printf("Enter the value to be deleted : ");
    scanf("%d",&num);
    if(head==NULL){
       printf("list is empty\n");
       return;
    }
    if(head->data==num)
    {
        head=head->next;
        free(temp);
        return;

    }
    else
    {
        while(temp->next!=NULL)
        {

            prv=temp;
            temp=temp->next;
            if(temp->data==num)
            {
                prv->next=temp->next;
                free(temp);
                return;
            }
        }

    }
}

void length()
{
    node *temp;
    int len=1;
    temp=head;
    if(head==NULL)
    {
        len=0;
    }
    else
    {
    while(temp->next!=NULL)
    {
        temp=temp->next;
        len++;
    }
    }
    printf("the length of the list is :%d",len);
}

void display()
{
        if(head==NULL){
    printf("list is empty\n");
    return;
    }
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
     printf("%d\t",temp->data);
     temp=temp->next;
    }
}
