# include<bits/stdc++.h>
using namespace std;

int main()
{
 
int x;
int sum=0;
sum=x+x;
// no of itration is 3 in above code or u as u can say O(3)
int n;
cin>>n;//no itration bcome O(5)
for (int i = 0; i < n; i++)//now itration becomeO(5)+O(n)
{
    int y;
    y=5;
    y++;//this all excutes 3 times means
    //now complexity become O(5)+O(3*n)
}

}