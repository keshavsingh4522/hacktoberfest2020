# include<bits/stdc++.h>
using namespace std;

int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s1,s2;
cin>>s1;
//cin breaks or it take input until the space or \
//thats why we use
getline(cin,s2);

int t;
cin>>t;
cin.ignore();//this ignore the endl create becoz zafter cin when we use getline our cursor move to next line thats why in out we get after 1 line 
while (t--)
{
    string s;
    getline(cin,s);
    cout<<s<<endl;
}

//dealing bignumbers
string s3;
cin>>s3;
int last_digit=s3[s3.size()-1]-'0';
cout<<last_digit;
//extracting the  digit for and performing the operations is used 

return 0;
}