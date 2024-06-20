int main()
{
int a;
star:
system("cls");
system("color F1");
printf("\t\t\t\t\t          CALENDAR\n\n\n");
printf("\t1. Year Calendar\n\n");
printf("\t2. Month by Month Calendar\n\n");
printf("\t3. Day from Date\n\n");
printf("\t4. Go to main menu\n\n");
printf("\t5. Exit");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter your selection : ");
scanf("%d",&a);
if(a==1)
yearcalendar();
if(a==2)
monbymon();
if(a==3)
dfd();
if(a==4)
main();
if(a==5)
return 0;
goto star;
}

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
" ",
"January",
"February",
"  March",
"  April",
"   May",
"  June",
"  July",
" August",
"September",
"October",
"November",
"December"
};

int yearcalendar()
{
int year,daycode,d1,d2,d3,month, day,a;
system("color F2");
fullyear:
system("cls");
printf("\t\t\t\t\t         YEAR CALENDAR\n\n\n");
printf("\n\tEnter a year (YYYY) : ");
scanf("%d", &year);
nextyear:
system("cls");
printf("loading");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
system("cls");
d1=(year-1)/4;
d2=(year-1)/100;
d3=(year-1)/400;
daycode =(year+d1-d2+d3)%7;
if(year%4==0 && year%100!=0 || year%400==0)
days_in_month[2]=29;
else
days_in_month[2]=28;
for(month=1;month<=12;month++)
{printf("\n\n\n\t  %s %d",months[month],year);
printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
for(day=1;day<=1+daycode*5;day++){
printf(" ");}
for(day=1;day<=days_in_month[month];day++)
{printf("%2d",day);
if((day+daycode)%7>0)
printf("   " );
else
printf("\n " );}
daycode=(daycode+days_in_month[month])%7;
sleep(1);}
printf("\n\n\nEnter 1 for next year, 0 to change year and 2 to go to calendar :");
scanf("%d",&a);
if(a==0)
goto fullyear;
if(a==1){
year++;
system("cls");
goto nextyear;}
if(a==2)
return 0;
}

int monbymon()
{
int year,daycode,d1,d2,d3,month, day, a;
system("color F3");
yearmonthbymonth:
system("cls");
printf("\t\t\t\t\t        MONTH CALENDAR\n\n\n");
printf("\n\tEnter a year (YYYY) : ");
scanf("%d", &year);
for(;year>0;year++){
d1=(year-1)/4;
d2=(year-1)/100;
d3=(year-1)/400;
daycode =(year+d1-d2+d3)%7;
if(year%4==0 && year%100!=0 || year%400==0)
days_in_month[2]=29;
else
days_in_month[2]=28;
for(month=1;month<=12;month++){
system("cls");
printf("\n\n\n\t  %s %d", months[month],year);
printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
for(day=1;day<=1+daycode*5;day++){
printf(" ");}
for(day=1;day<=days_in_month[month];day++){
printf("%2d",day);
if((day+daycode)%7>0)
printf("   " );
else
printf("\n " );}
daycode=(daycode+days_in_month[month])%7;
printf("\n\n\n\n\n\n\n\n\npress 1 for next month, 0 to change the year and 2 to go to calendar : ");
scanf("%d",&a);
if(a==0)
goto yearmonthbymonth;
if(a==2)
return 0;
}}}

int dfd(){
int d,m,y,a;
system("color F4");
start:
system("cls");
printf("\t\t\t\t\t         DAY FROM DATE\n\n\n");
printf("\n\tEnter the date  : ");
scanf("%d",&d);
printf("\tEnter the month : ");
scanf("%d",&m);
printf("\tEnter the year  : ");
scanf("%d",&y);
if(d>=32||m>=13||y/10000!=0||y/1000==0)
printf("\n\n\n\n\nPlease enter correct date\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
else
day(d,m,y);
sleep(1);
end:
printf("press 1 to run program again, press 2 for calendar : ");
scanf("%d",&a);
if(a==1)
goto start;
else if(a==2)
return 0;
else{
printf("enter correct selection - ");
goto end;
}
}

int day(int date,int month,int year) {
int day,yr,yd;
yr = year % 100;
yd = year / 100;
day=1.25*yr+findm(month,year)+date-2*(yd % 4);
day=day%7;
printf("\n\n\n\n\tloading");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
printf("\n\n\n\n\tThe Given Date is : %d/%d/%d \n", date, month, year);
printf("\n\t");
switch (day){
case 0:printf("Day is : Saturday\n\n\n\n\n\n\n\n\n\n\n");
break;
case 1:printf("Day is : Sunday\n\n\n\n\n\n\n\n\n\n\n");
break;
case 2:printf("Day is : Monday\n\n\n\n\n\n\n\n\n\n\n");
break;
case 3:printf("Day is : Tuesday\n\n\n\n\n\n\n\n\n\n\n");
break;
case 4:printf("Day is : Wednesday\n\n\n\n\n\n\n\n\n\n\n");
break;
case 5:printf("Day is : Thursday\n\n\n\n\n\n\n\n\n\n\n");
break;
case 6:printf("Day is : Friday\n\n\n\n\n\n\n\n\n\n\n");
break;
default:printf("Please enter correct date .\n\n\n\n\n\n\n\n\n\n\n");}
return 0;
}
int findm(int mo,int ye){
int d,leap;
if ((ye%100==0)&&(ye%400!=0))
leap=0;
else if (ye%4==0)
leap=1;
else
leap=0;
d=3+(2-leap)*((mo+2)/(2*mo))+(5*mo+mo/9)/2;
d%=7;
return d;
}
