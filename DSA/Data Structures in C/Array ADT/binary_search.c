#include<stdio.h>
#include<math.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}
void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}
void Insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index <=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}
void delete(struct Array *arr,int index){
    if(index>=0 && index<arr->length){
        
        for(int i=index;i<arr->length- 1;i++){
            arr->A[i]=arr->A[i+ 1];
        }
        arr->length--;
    }
}
int swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int linear_search(struct Array *arr,int key){
    for(int i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            swap(&arr->A[i],&arr->A[i- 1]);
            return i+ 1;
            //move to front/head
            //swap(&arr->A[i],&arr->A[i- 1]);
        }
    }
    return 0; 
}
int binary_search(struct Array arr,int key){
    int h=arr.A[arr.length- 1];
    int l=arr.A[0];
    while(l<=h){
        int mid=floor((l+h)/2);
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h=mid- 1;
        }
        else{
            l=mid+ 1;
        }
    }
    return -1;
    
}
int main()
{
    struct Array arr1={{1,2,3,4,5,6,7,8},10,8};
    //Append(&arr1,10);
    //Insert(&arr1,0,12);
    //delete(&arr1,arr1.length-1);
    //Display(arr1);
    //printf("\n");
    //printf("%d",linear_search(&arr1,8));
    //printf("\nArray after linear_search");
    //Display(arr1);
    printf("\nArray after bianary_search\n");
    printf("%d",binary_search(arr1,6));
    Display(arr1);
    return 0;
}
