#include<stdio.h>
#include<stdlib.h>
typedef struct node node;

int isempty();
int isfull();
void enqueue();
void dequeue();
int length();
void pfront();
void prear();

struct node{
    int data;
    node *next;
};

node *head=NULL;
node *tail=NULL;

int length()
{
    node *temp;
    int len=0;
     temp=head;
    if(head==NULL)
        return 0;
    else
    {

        while(temp!=NULL)
        {

            temp=temp->next;
            len+=1;
        }

    }
    return len;


}

int isempty()
{
    int i=length();
    if(i==0)
    {
         printf("\nQueue is empty\n");
        return 1;
    }
    else
        return 0;
}

int isfull()
{
    int i=length();
    if(i==5)
    {
        printf("\nQueue is full\n");
        return 1;
    }
    else
        return 0;

}

void enqueue()
{
   node *newnode,*temp;
   int num;

   printf("\nEnter the value to be enqueued : ");
   scanf("%d",&num);

   newnode=malloc(sizeof(node));

   newnode->data=num;
   newnode->next=NULL;



   if(head==NULL)
   {
       head=newnode;
       tail=head;
   }
   else if(length()<5)
   {

       temp=head;
       while(temp->next!=NULL)
       {
          temp=temp->next;
       }
       temp->next=newnode;
       tail=newnode;
   }
}

void dequeue()
{
    node *temp;
    temp=head;
    head=head->next;
    free(temp);

}

void display()
{
   node *temp;
   temp=head;
   if(head==NULL)
    return;
   else{
   while(temp!=NULL)
   {
     printf("%d  ",temp->data);
     temp=temp->next;
   }
   }
}

void pfront()
{
    if(head==NULL)
        printf("Queue is empty");

      else
    printf("Front value in the queue is : %d",tail->data);
}

void prear()
{   if(head==NULL)
        printf("Queue is empty");

      else
      {
          printf("Rear value in the queue is : %d",head->data);
      }
}

int main()
{
    printf("IMPLEMENTATION OF QUEUE");
    int choice;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Head\n5.Rear\n6.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(isfull())
                break;
            else
                enqueue();
            break;
        case 2:
            if(isempty())
                break;
            else
                dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            pfront();
            break;
        case 5:
            prear();
            break;
        case 6:
            exit(0);
        }
    }


    return EXIT_SUCCESS;
}

