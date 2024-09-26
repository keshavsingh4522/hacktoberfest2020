/*Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given 
s1 = ABCD and s2 = CDAB, return true, 
given s1 = ABCD, and s2 = ACBD , return false)*/

#include<iostream>
#include<string>
using namespace std;

void place(string s1,string s2)
{
    int index = s2.find(s1[0]);
    int i=0,j=index;
    //cout<<j<<endl;
    int flag=0;
    while(i<s1.length())
    {
    cout<<i<<" "<<j<<endl;
       if(s1[i]!=s2[j])
       {
          flag=1;
       }
       i++;
       j++;
       if(j>s2.length()-1)
       {  
           cout<<j<<endl;
           j=0;
       }
    }
    if(flag==1)
    {
        cout<<"Not Equal"<<endl;
    }
    else
    {
        cout<<"equal";
    }
}


int main()
{
    string s1 = "ABCD";
    string s2 = "CDAB";
    
    place(s1,s2);
    
}
