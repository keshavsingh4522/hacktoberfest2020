#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

void LongestPlindrome(string s)
{
    int n=s.length();
    cout<<n<<endl;
    int maxLen=0;
    
    int right=0;
    int left=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
              string norm=s.substr(i,j+1);
              
              string rev=norm;
              
              reverse(rev.begin(),rev.end());
              cout<<norm<<endl;
              /*if(norm.compare(rev)==0)
              {
                  if(maxLen<rev.length())
                  {
                      maxLen=rev.length();
                      right=i;
                      left=j;
                  }
              }*/
        }
    }
    cout<<maxLen<<" ";
    
    cout<<s.substr(right,left-1);
        
    }

int main() {
    int i;
    cin>>i;
    while(i)
    {
	  string str;
	  cin>>str;
     LongestPlindrome(str);
	  i--;
    }
	return 0;
}
