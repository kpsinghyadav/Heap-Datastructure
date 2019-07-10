//.....imlementation of Extract-Max Heap............
#include<stdio.h>
#include<conio.h>
void buildHeap(int *a,int size);
void maxHeapify(int*a,int,int);
int Heap_extractmax(int* a,int* size);
void main()
{
    int maxelement;
    int a[7]={4,2,5,8,7,6,9};
    int size=sizeof(a)/sizeof(a[3]);
    printf("array beore heap:\n");
    for(int i=0;i<size;i++)
        printf("%2d",a[i]);
    buildHeap(a,size);//BUILDING MAX HEAP OF ARRAY
     printf("\narray after heap:\n");
    for(int i=0;i<size;i++)
        printf("%2d",a[i]);
     do{
          maxelement=Heap_extractmax(a,&size);
         printf("\narray after extract max:%4d\n",maxelement);
         for(int i=0;i<size;i++)
         printf("%2d",a[i]);
     }while(size);

}
void buildHeap(int* a,int size)
{
    int i=size/2;
    for(i;i>=0;i--)
        maxHeapify(a,i,size);
}
void maxHeapify(int* a,int i,int size)
{
    int l=i*2+1;
    int r=i*2+2;
    int largest=i;
    if(l<size&&a[l]>a[i])
        largest=l;
    if(r<size&&a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        maxHeapify(a,largest,size);
    }
}
int Heap_extractmax(int* a,int* size)
{
    if(*size<1)
    {
        printf("ERROR-underow");
        return 0;
    }
    int max=a[0];
    a[0]=a[*size-1];
    *size=*size-1;
    maxHeapify(a,0,*size);
    return max;

}
