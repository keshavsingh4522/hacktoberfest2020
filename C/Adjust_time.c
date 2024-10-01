#include<stdio.h>
#include<stdlib.h>

int checkFor24(int temp){
    if(temp>=24)
        return(temp%24);
    else
        return temp;
}
int checkFor60(int temp){
    if(temp>=60)
        return(temp%60);
    else
        return temp;
}
int main()
{
    int hr,min,sec,x,y,z;
    scanf("%02d:%02d:%02d\n%d %d %d",&hr,&min,&sec,&x,&y,&z);
    hr = checkFor24(hr+x);
    printf("%02d:%02d:%02d\n",hr,min,sec);
    
    if((min+y)>=60)
    {
        hr = checkFor24(hr+((min+y)/60));
        min = checkFor60(min+y);
    }
    else min += y;
    printf("%02d:%02d:%02d\n",hr,min,sec);
    
    if((sec+z)>=60)
    {
        hr = checkFor24(hr+(min+((sec+z)/60))/60);
        min = checkFor60(min+((sec+z)/60));
        sec = checkFor60(sec+z);
    }
    else sec += z;
    printf("%02d:%02d:%02d ",hr,min,sec);
}
