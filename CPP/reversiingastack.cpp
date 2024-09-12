# include<bits/stdc++.h>
using namespace std;

int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int a[n];
stack<int> m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<" Original Stack \n";
for(int i=n-1;i>0;i--){
   cout<<a[i];
}
cout<<endl;
while(!m.empty()){

}
return 0;
}