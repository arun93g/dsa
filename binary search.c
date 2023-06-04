#include<stdio.h>
#include<stdlib.h>
#include<string.h>

swap(int *p,int *p1)
{
    int temp;
    temp=*p;
    *p=*p1;
    *p1=temp;
}


int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb,end=ub;
    while(start<=end)
    {
    while(arr[start]<=pivot)
    {
        start++;
    }
    while(arr[end]>pivot)
    {
        end--;
    }
    if(start<end)
    {
        swap(&arr[start],&arr[end]);
    }
    swap(&arr[lb],&arr[end]);
    }
    return end;

}



void quicksort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int i=partition(arr,lb,ub);
        quicksort(arr,lb,i-1);
        quicksort(arr,i+1,ub);
    }
}

int binarysearch(int arr[],int start,int end,int num)
{
    int mid;
//    while(start<=end)
//    {
//     mid=(start+mid)/2;
//    }
   // int value=num;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==num)
        {

            return mid;
        }
        if(arr[mid]<num)
        {
            start=mid+1;
        }
        else
        {
           end=mid-1;
        }
    }
    return -1;
}


int main()
{
    int arr[]={8,1,4,7,2,98,54,21,57,42,14};
    quicksort(arr,0,10);
    for(int i=0;i<11;i++)
    {
        printf("%d ",arr[i]);
    }
   int i= binarysearch(arr,0,10,54);
   if(i==-1)
    printf("\nnot found");
   else
    printf("\nIndex value of the number is : %d",i);
    return EXIT_SUCCESS;
}
