#include <iostream>
#include<cstring>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	int i;
	for(i=0;i<t;i++)
	{
	    string s;
	    cin>>s;
	    int count=0;
        bool prefree = true;
        int j;
        for(j=1;j<s.size();j++)
        {
            if(s[j]!=s[j-1] && prefree)
            {
                prefree = false;
                count++;
            }
            else
            {
                prefree = true;
            }
        }
        cout<<count<<endl;
	    
	    
	}
	return 0;
}
