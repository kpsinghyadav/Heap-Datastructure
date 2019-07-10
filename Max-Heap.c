//....implementation of max heap using array....

#include<stdio.h>
#include<stdlib.h>
void maxHeap(int *a,int,int);
void buildHeap(int*a,int);
void main()
{
    int a[7]={4,2,5,8,7,6,9};          //its used as input array,we can take this input from user.
    int size=sizeof(a)/sizeof(a[3]);
     printf("initially array is:");
    for(int i=0;i<size;i++)
        printf("%3d",a[i]);

    buildHeap(a,size);                //calling funtion Buildheap to create heap on given array element

    printf("\narray after convertint to heap:\n");  //
    for(int i=0;i<size;i++)
        printf("%3d",a[i]);
}
void buildHeap(int *a,int size)
{
    int i=size/2;
    for(i;i>=0;i--)
        maxHeap(a,i,size);
}
void maxHeap(int* a,int i,int size)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<size && a[l]>a[i])
        largest=l;
    if(r<size && a[r]>a[largest])
            largest=r;
    if(largest!=i)
    {
       int temp=a[i];
       a[i]=a[largest];
       a[largest]=temp;
       maxHeap(a,largest,size);
    }
   else return;
}
