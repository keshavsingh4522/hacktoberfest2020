#include<iostream>

using namespace std;
int main()
{
   float p, r, t, si;
   char ch;
   cout<<"Enter Principle Amount: ";
   cin>>p;
   cout<<"Enter Rate of Interest: ";
   cin>>r;
   cout<<"Time Period in Year or Month ? (y for year, m for month): ";
   cin>>ch;
   if(ch=='y')
   {
      cout<<"Enter Time Period (in Years): ";
      cin>>t;
      si = (p*r*t)/100;
   }
   else
   {
      cout<<"Enter Time Period (in Months): ";
      cin>>t;
      t = t/12;
      si = (p*r*t)/100;
   }
   cout<<"\nSimple Interest Amount: "<<si;
   cout<<endl;
   return 0;
}
