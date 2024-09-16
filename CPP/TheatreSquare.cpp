#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define sum(v) accumulate(v.begin(),v.end(),0)
#define sort(v) sort(v.begin(),v.end())
#define rsort(v) reverse(v.begin(),v.end())
#define mseti multiset<int>
#define vi vector<int>
#define pb push_back
#define fo(i,o,n) for (int i = o; i < n; i++)
#define tc   \
   int t;    \
   cin >> t; \
   while(t--)
#define i(n) \
   int n;    \
   cin >> n;
#define printn(x) cout << x << endl
#define prints(x) cout << x << " "
#define print(x) cout << x

signed main ()
{
   // tc
   // {
         i(n);i(m);i(a);
         int flag;
         int x = n + (a - (n%a));
         int y = m + (a - (m%a));

         if (n%a==0 && m%a==0)
            flag=(n*m)/(a*a);
         else if (n%a==0 && m%a!=0)
         {
            flag = (n*y)/(a*a);
         } 
         else if (n%a!=0 && m%a==0)
         {
            flag = (x*m)/(a*a);
         }
         else
         {
            flag = (x*y)/(a*a);
         }

         printn(flag);
   // }
}
