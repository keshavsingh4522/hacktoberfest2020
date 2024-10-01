#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    float p;
    float m;
    printf("enter the no of objects\n");
    scanf("%d",&n);
    float price[n];
    float weight[n];
    float p_w[n];
    printf("price of objects\n");
    for(int i=0;i<n;i++)
    {
        printf("price of %d obj = ",i+1);
        scanf("%f",&price[i]);
    }
    printf("weight of objects\n");
    for(int i=0;i<n;i++)
    {
        printf("weight of %d obj = ",i+1);
        scanf("%f",&weight[i]);
    }
    printf("enter the max weight\n");
    scanf("%f",&m);
    for(int i=0;i<n;i++)
    {
       p_w[i]=price[i]/weight[i];
    }

    for(int k=0;k<n-1;k++)
    {
        for(int j=0;j<n-k-1;j++)
        {
            if(p_w[j]<p_w[j+1])
            {
                int temp=p_w[j];
                p_w[j]=p_w[j+1];
                p_w[j+1]=temp;
                
                int temp1=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp1;
 
                int temp2=price[j];
                price[j]=price[j+1];
                price[j+1]=temp2;
            }
        }
    }
 
    for(int i=0;i<n;i++)
    {
        if(m>0 && weight[i]<=m)
        {
            m=m-weight[i];
            p=p+price[i];
        }
        else
              p=p+price[i]*(m/weight[i]);
    }
printf("total price is %f ",p);
}