#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,p;
    int i,j,a[100];
    std::getline(std::cin, s);
    std::getline(std::cin, p);
    a[0]=0;
    i=1;
    j=0;
   while(i<p.length()) // Creation of Suffix prefix array
    {
        if(p[i]==p[j])
        {
            a[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j==0)
            {
                a[i]=0;
                i++;
            }
            else
            {
                j=a[j-1];
            }
        }
    }
    i=0;
    j=0;
    while(i<s.length())   // Pattern Matching
    {
        if(s[i]==p[j])
        {
            if(j==p.length()-1)
            {
              cout << "Pattern found at : " << i-p.length()+1 << "\n";
              j=0;
              i++;
            }
            else
            {
            i++;
            j++;
            }
        }
        else if(i<s.length()&&p[j]!=s[i])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=a[j-1];
            }
        }
    }
}
