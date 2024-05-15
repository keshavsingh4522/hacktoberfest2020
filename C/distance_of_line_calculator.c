#include<stdio.h>
#include<math.h>

struct point{
    float x,y;
};

void main()

{
    int i=0;
    float sum[100];
    struct point p1, p2, p3, p4;
    for(i=1;i<=2;i++)
    {
        printf("\n %d.Enter the value for X1 and X2:",i);
        scanf("%f%f",&p1.x,&p2.x);
        printf("\n %d.Enter the value for Y1 and Y2:",i);
        scanf("%f%f",&p3.y,&p4.y);
        sum[i]=sqrt(pow((p2.x-p1.x),2)+pow((p4.y-p3.y),2));
        printf("\nDistance d[%d]:%f",i,sum[i]);
    }
    printf("\nDistance=%f",sum[1]+sum[2]);
}