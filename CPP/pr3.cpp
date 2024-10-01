#include <stdio.h>
int main(void) {
    int T,a,b,c,d,i;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        printf("\n");
        if(a == b == c == d)
        printf("YES\n");
        else if(a == b && c == d)
         printf("YES\n");
        else if(a == d && c == b)
         printf("YES\n");
        else if(a == c && b == d)
         printf("YES\n");
        else
         printf("NO\n");
    }
	return 0;
}
