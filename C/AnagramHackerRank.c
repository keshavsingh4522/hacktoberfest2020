#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,len,n,c=0,p,q;
	    char str[100],str1[100],str2[100],temp;
		puts("Enter the String");
		gets(str);
		len=strlen(str);
		for(i=0;i<(len/2);i++)
		{
			str1[i]=str[i];
		}
		for(i=(len/2);str[i]!='\0';i++)
		{
			str2[c]=str[i];
			c++;
		}
		for (i=0;str1[i]!='\0'; i++) 
        { 
        for (j=i+1;str1[j]!='\0'; j++) 
        { 
            if(str1[i]>str1[j])
			{
				temp=str1[i];
				str1[i]=str1[j];
				str1[j]=temp;
			}
        } }
        
        for (p=0;str2[p]!='\0'; p++) 
        { 
        for (q=p+1;str2[q]!='\0'; q++) 
        { 
            if (str2[p]>str2[q]) 
            { 
                temp=str2[p];
				str2[p]=str2[q];
				str2[q]=temp; 
            } 
        } 
       } 
	puts(str1);
	puts(str2);	
		
	
}
