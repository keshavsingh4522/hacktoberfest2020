#include <iostream>

using namespace std;

int main() {

	// your code goes here	int t;

	cin>>t;

	while(t--)

	{

	    int a,b,c,d,e;

	    cin >> a >> b >> c>> d >> e;

	    if(((a+b<=d) && c<=e) || ((c+b<=d) &&  a<=e) || ((a+c<=d) && b<=e))

	    {

	       cout << "Yes\n"; 

	    }

	    else

	    {

	        cout << "No\n";

	    }

	}

	return 0;

}
