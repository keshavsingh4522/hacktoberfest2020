#include<bits/stdc++.h>
using namespace std;

bool checkpalindrome(char a[], int n)
{
   int s = 0;
   int e = n-1;

   while ( s <= e)
   {
      if ( a[s] != a[e])
      {
         return false;
      }
      else 
      {
         s++;
         e--;
      }
   }
   return true;
}

void reverse(char name[], int n)
{
   int count = 0;
   int s =0;
   int e = n-1;
   while ( s < e)
   {
     swap(name[s++], name[e--]); 
   }
}

int getlength(char name[])
{
    int count = 0;
   for (int i =0;  name[i]!= '\0'; i++)
   {
    count ++;
   }
   return count++;
}

int main()
{
   char name[20];
   cout << " Enter your name: ";
   cin >> name;

   cout << " Your name is ";
   cout << name << endl;

   int leng = getlength(name);
   cout << "length is " << leng << endl;

   reverse(name, leng);
   cout << "Reverse name is "<< name << endl;

   cout << " Plindrome or not " << checkpalindrome(name, leng) << endl;
}