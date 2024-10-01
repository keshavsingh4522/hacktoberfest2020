#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void hicm()
{
	float no,nocov;
	printf("Enter your height :");
	scanf("%f", &no);
	nocov=no/30.48;
	printf("\nYour height in feet is %f",nocov);
}
void hift()
{
	float no,nocov;
	printf("Enter your height :");
	scanf("%f", &no);
	nocov=no*30.48;
	printf("\nYour height in cm is %f",nocov);
}
void yes()
{
	printf("1) From cm to feet \n2) For feet to cm\n3) Exit");
}

void no()
{
	printf("No Problem");
}
int main()
{
	int ch,ch1;
	
	printf("Do you want to know your height ?\n");
	printf("1) From cm to feet \n2) For feet to cm \n3) Exit");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:hicm();
			       break;       
			case 2:hift();
			       break;		
			case 3:exit(0);	
			default:printf("Invalid Choice\n");	        
 	    }
 	    
 	    printf("\nDo you want to print menu (0/1)");
 	    
 	    printf("\nType.... \n");
 	    scanf("%d",&ch1);
 	    
 	    switch(ch1)
 	    {
 	    	case 0:yes();
 	    	       break;
 	    	case 1:no();
 	    	       exit(0);
			       break;     
			default:printf("Incorrect Value");	        
		 }
	}
	return 0;
}
