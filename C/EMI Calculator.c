//EMI Calculator 
#include <stdio.h>
#include <math.h>

int main()
{
    float principal_amount, roi, time, emi;

    printf("Enter your principal amount : ");
    scanf("%f", &principal_amount);

    printf("Enter rate of interest: ");
    scanf("%f",&roi);

    printf("Enter your loan time in years: ");
    scanf("%f",&time);

    roi = roi/(12*100); /*interest for one month*/
    time=time*12;       /*time for one month*/

    emi= (principal_amount*roi*pow(1+roi,time))/(pow(1+roi,time)-1);

    printf("Monthly EMI = %0.2f\n",emi);
   
    return 0;
}
