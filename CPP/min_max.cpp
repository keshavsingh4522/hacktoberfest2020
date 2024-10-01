#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cout << " Enter the array number you want:" << endl;
cin >> n;
int num[n];
cout << " Enter the numbers you want to find:" << endl;
for ( int i = 0; i < n; i++)
{
  cin >> num[i];
}
cout << endl;

int min = num[0];
int max = num[0];

for ( int i = 0; i < 5; i++)
{
   if ( num[i] < min)
   {
    min = num[i];
   }
   else if ( num[i] > max)
   {
    max = num[i];
   }
}
  cout << " Minimun number is: " << min << endl;
  cout << " Minimun number is: " << max << endl;

}

