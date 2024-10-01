#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void FtoC()
{
	float f,c,c1,c2;
	printf("Enter any number : ");
	scanf("%f",&f);
	printf("Enter number is %f F",f);
	c=f-32;
	c1=c*5;
	c2=c1/9;
	printf("\nNumber is %f C",c2);
}

void CtoF()
{
	float c,f,f1,f2;
	printf("\nEnter any number : ");
	scanf("%f",&c);
	printf("Enter number is %f C",c);
	f=c/5;
	f1=f*5;
	f2=f1+32;
	printf("\nNumber is %f F",f2);
}

void KtoC()
{
	float k,c;
	printf("\nEnter any number : ");
	scanf("%f",&k);
	printf("Enter number is %f K",k);
	c = k - (273.15);
	printf("\nNumber is %f C",c);
}

void CtoK()
{
	float c,k;
	printf("\nEnter any number : ");
	scanf("%f",&c);
	printf("Enter number is %f C",c);
	k = c + (273.15);
	printf("\nNumber is %f K",k);
}

void KtoF()
{
	float k,f,c1,c2;
	printf("\nEnter any number : ");
	scanf("%f",&k);
	printf("Enter number is %f K",k);
	c1=k-273.15;
	c2=c1*1.8;
	f=c2+32;
	printf("\nNumber is %f F",f);
}

void FtoK()
{
	float f,k,k1,k2,k3;
	printf("\nEnter any number : ");
	scanf("%f",&f);
	printf("Enter number is %f F",f);
	k=f-32;
	k1=k*5;
	k2=k1/9;
	k3=k2+273.15;
	printf("\nNumber is %f K",k3);
}

void yes()
{
	printf("1) From FtoC \n2) From CtoF \n3) From KtoC \n4) From CtoK \n5) From KtoF \n6) From FtoK \n7) Exit");
}

void no()
{
	printf("No Problem");
}

int main()
{
	int ch,ch1;
	
	printf("Do you want to know temperature ?\n");
	printf("1) From FtoC \n2) From CtoF \n3) From KtoC \n4) From CtoK \n5) From KtoF \n6) From FtoK \n7) Exit");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:FtoC();
			       break;       
			case 2:CtoF();
			       break;
			case 3:KtoC();
				   break;
			case 4:CtoK();
				   break;
			case 5:KtoF();
				   break;
			case 6:FtoK();
				   break;	
			case 7:exit(0);	
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
