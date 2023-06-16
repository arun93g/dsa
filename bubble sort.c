#include<stdio.h>
void swap(int *p1,int *p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}


void bubblesort(int arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

}

int main()
{
    int arr[] = { 1, 7, 4, 2, 5, 8, 9, 55, 22, 6, 2, 15 };
    bubblesort(arr,12);
    for (int i = 0; i < 12; i++)
    {
      printf ("%d ", arr[i]);
    }
    return 0;


}
