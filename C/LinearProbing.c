#include<stdio.h>
int hash(int key)
{
    return key % 10;
}
int prob(int H[],int key)
{
    int i;
    i = 0;
    while (H[(hash(key) + i) % 10] != 0)
    {
        i++;
    }
    return (hash(key) + i) % 10;
}
void insert(int H[],int key)
{
    int index;
    index = hash(key);
    if(H[index] != 0)
        index = prob(H, key);
    H[index] = key;
}
int search(int H[],int ele)
{
    int index,i;
    index = hash(ele);
    i=0;
    while (H[(index + i) % 10] != ele)
    {
        i++;
    }
    return (index + i) %10;
}
int main()
{
    int HT[10] = {0},n,i,ele,searchIndex;
    printf("Enter the number of elements that you want to enter");
    scanf("%d", &n);
    if(n/10 <=0.5)
    {
        for (i = 0; i < n;i++)
        {
            scanf("%d", &HT[i]);
        }
         for (i = 0; i < n;i++)
        {
            insert(HT, HT[i]);
        }
    }
    else
    {
        printf("\n!!!ERROR!!! : Loading factor is greater than 0.5\n\n");
    }
    printf("Enter the element to be searched for");
    scanf("%d", &ele);
    searchIndex = search(HT,ele);
    printf("Element found at index %d",searchIndex);
    return 0;
}
