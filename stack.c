#include<stdio.h>
#include<stdlib.h>
#define size 5
void push();
void pop();
void display();

typedef struct stack stack;

struct stack{
   int arr[size];
   int top;
}st;
int full()
{
    if(st.top>=size-1)
        return 0;
    else
        return 1;
}

int empty()
{
    if(st.top!=-1)
        return 1;
    else
        return 0;
}
void push()
{
    int value;
    printf("enter the value to be pushed : ");
    scanf("%d",&value);
    st.top++;
    st.arr[st.top]=value;
}

void pop()
{
    st.top--;
}

void display()
{
    stack *temp;
    temp=(stack*)malloc(sizeof(stack));
    temp=&st;
    if(temp->top==-1)
        printf("stack is empty");
    else
    {
    for(int i=temp->top;i>=0;i--)
    {

        printf("%d  ",temp->arr[i]);

    }
    }

}

int main()
{
    st.top=-1;
    int choice;
    printf("stack implementation");
    while(1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit");
        printf("\nenter your choice :");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            if(full())
            push();
            else
                printf("stack is full\n");
            break;
        case 2:
            if(empty())
            pop();
            else
                printf("stack is empty");
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("enter correct  choice");
        }
    }
}
